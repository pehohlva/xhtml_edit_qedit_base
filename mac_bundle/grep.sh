#!/bin/bash
#
# Configuration start
#

# relative path to the directory which contains the created app bundle
BIN_DIR="bin"
# name of the binary
BINARY_NAME="edithtml"
# Qt libraries you've linked against on apps remove not needed libs
declare -a NEEDED_LIBS=( "QtCore" "QtGui" "QtXml" "QtSql" "QtNetwork" "QtOpenGL" "QtSvg")
# additional files you'd like to get copied to the final dmg inside DMG not bundle!
declare -a ADD_FILES=("bin/ticket.pdf" "bin/copying.txt")

#
# Configuration end, nothing should be edited from here on
#
#  on main.cpp
#if defined Q_WS_MAC
#QStringList path;
#path.append(QApplication::applicationDirPath());
#QDir dir(QApplication::applicationDirPath());
#dir.cdUp();
#path.append(dir.absolutePath());
#dir.cd("plugins");
#path.append(dir.absolutePath());
#dir.cdUp();
#path.append(dir.absolutePath());
#QApplication::setLibraryPaths(path);
#QDir::setCurrent(dir.absolutePath());   /* here down -> Frameworks */
#endif

bundle_dir="$BIN_DIR/$BINARY_NAME.app"
bundle_bin="$bundle_dir/Contents/MacOS/$BINARY_NAME"
framework_dir="$bundle_dir/Contents/Frameworks"

#### make plugin && locale dir after the before the 2° run oft this script copy image sql
#### plugin inside...  or at end right click apps and info apps select locale to activate...

plugin_dir="$bundle_dir/Contents/plugins"
locale_dir="$bundle_dir/Contents/locale"

if [ -z $QTDIR ]; then
   echo "\$QTDIR environment variable not found... exiting."
   exit 1
fi

# canonicalize QtDir, unfortunately this bash has no realpath() implementation
# so we need to use perl for this
QTDIR=`perl -e "use Cwd 'realpath'; print realpath('$QTDIR');"`

if [ ! -d "$bundle_dir" ]; then
   echo "Application bundle not found in bin... exiting."
   exit 1
fi

echo "Creating Frameworks directory in application bundle..."
mkdir -p "$framework_dir"
mkdir -p $plugin_dir
mkdir -p $locale_dir

libcount=${#NEEDED_LIBS[@]}
for (( i = 0 ; i < libcount ; i++ ))
do
    lib=${NEEDED_LIBS[$i]}
    echo "Processing $lib..."
   
    if [ ! -d "$QTDIR/lib/$lib.framework" ]; then
        echo "Couldn't find $lib.framework in $QTDIR."
        exit 1
    fi

    rm -rf "$framework_dir/$lib.framework"
    cp -fR "$QTDIR/lib/$lib.framework" "$framework_dir"
    echo "...$lib copied."
   
    install_name_tool \
        -id "@executable_path/../Frameworks/$lib.framework/Versions/4/$lib" \
        "$framework_dir/$lib.framework/Versions/4/$lib"
   
    # other Qt libs depend at least on QtCore
    if [ "$lib" != "QtCore" ]; then
        install_name_tool -change "$QTDIR/lib/QtCore.framework/Versions/4/QtCore" \
            "@executable_path/../Frameworks/QtCore.framework/Versions/4/QtCore" \
            "$framework_dir/$lib.framework/Versions/Current/$lib"
    fi
   
    install_name_tool -change "$QTDIR/lib/$lib.framework/Versions/4/$lib" \
        "@executable_path/../Frameworks/$lib.framework/Versions/4/$lib" \
        "$bundle_bin"
       
    echo "...$lib done."
done


echo "Removing any debug libraries and headers..."
find "$framework_dir" | egrep "debug|Headers" | xargs rm -rf

echo "Preparing image directory..."
tempdir="/tmp/`basename $0`.$$"
mkdir $tempdir
cp -R $bundle_dir $tempdir
echo "...Bundle copied"
fcount=${#ADD_FILES[@]}
for (( i = 0 ; i < fcount ; i++ )) do
    file=${ADD_FILES[$i]}   
    if [ ! -f "$file" ]; then
        echo "WARNING: $file not found!"
    else
        cp "$file" $tempdir
        echo "...$file copied"
    fi
done
echo "Creating disk image..."
rm -f "$BIN_DIR/$BINARY_NAME.dmg"
# format UDBZ: bzip2 compressed (10.4+),  UDZ0: zlib compressed (default)
hdiutil create -srcfolder $tempdir -format UDBZ -volname "$BINARY_NAME" "$BIN_DIR/$BINARY_NAME.dmg"
rm -rf $tempdir 