set -e

rm -rf build
mkdir build
cd build

curl -O https://dilborceisv8p.cloudfront.net/bsf_2019.06.07_win64.zip
unzip bsf_2019.06.07_win64.zip -d bsf

cmake -Dbsf_INSTALL_DIR=. -DCMAKE_BUILD_TYPE=RelWithDebInfo -DREGOTH_USE_SYSTEM_BSF=On -A x64 ../..
cmake --build . --config RelWithDebInfo --parallel
