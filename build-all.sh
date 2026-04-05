#!/bin/bash
set -e

echo "=== Building Linux ==="
cmake -B build/linux -DCMAKE_BUILD_TYPE=Release
cmake --build build/linux
(cd build/linux && cpack -C Release)

echo "=== Building Windows ==="
cmake -B build/windows -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-windows.cmake
cmake --build build/windows
(cd build/windows && cpack -C Release)

echo "=== Cleaning up ==="
# Переносим архивы в build/
mv build/linux/*.tar.gz build/
mv build/windows/*.zip build/

# Удаляем всё кроме архивов
find build/ -mindepth 1 -maxdepth 1 ! -name "*.tar.gz" ! -name "*.zip" -exec rm -rf {} +

echo "=== Done ==="
ls build/
