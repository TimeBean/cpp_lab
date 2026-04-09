#!/bin/bash
set -e

echo "=== Building Linux ==="
cmake -B build/linux -DCMAKE_BUILD_TYPE=Release
cmake --build build/linux
(cd build/linux && cpack -C Release)

echo "=== Building Windows (static) ==="
cmake -B build/windows -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-windows.cmake \
  -DCMAKE_EXE_LINKER_FLAGS="-static -static-libgcc -static-libstdc++" \
  -DCMAKE_SHARED_LINKER_FLAGS="-static -static-libgcc -static-libstdc++" \
  -DBUILD_SHARED_LIBS=OFF
cmake --build build/windows
(cd build/windows && cpack -C Release)

echo "=== Cleaning up ==="
mv build/linux/*.tar.gz build/
mv build/windows/*.zip build/

find build/ -mindepth 1 -maxdepth 1 ! -name "*.tar.gz" ! -name "*.zip" -exec rm -rf {} +

echo "=== Done ==="
ls build/
