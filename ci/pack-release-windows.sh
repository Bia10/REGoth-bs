set -e

INTERNAL_DIR=artifacts

rm -rf ./$INTERNAL_DIR

mkdir $INTERNAL_DIR

cp ../README.md $INTERNAL_DIR/
cp ../LICENSE $INTERNAL_DIR/
cp -r ../content $INTERNAL_DIR/
cp -r build/bin/Release/*.exe $INTERNAL_DIR/
cp -r build/bin/Release/*.dll $INTERNAL_DIR/
cp -r build/bsf/bin/* $INTERNAL_DIR/
