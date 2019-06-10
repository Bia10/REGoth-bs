set -e

rm -rf build
mkdir build
cd build

wget https://dilborceisv8p.cloudfront.net/bsf_2019.06.06_linux.tar.gz

mkdir bsf
tar -xf bsf_2019.06.06_linux.tar.gz -C bsf

cmake -Dbsf_INSTALL_DIR=. -DCMAKE_BUILD_TYPE=RelWithDebInfo -DREGOTH_USE_SYSTEM_BSF=On ../..
cmake --build . --config RelWithDebInfo --parallel
