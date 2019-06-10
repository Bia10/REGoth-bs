set -e

INTERNAL_DIR=REGoth-ci-build

rm -rf ./$INTERNAL_DIR

mkdir $INTERNAL_DIR

cp ../README.md $INTERNAL_DIR/
cp ../LICENSE $INTERNAL_DIR/
cp -r ../content $INTERNAL_DIR/
cp -r build/bin/* $INTERNAL_DIR/
