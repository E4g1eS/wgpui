# wgpui

To compile:

`emcc main.cpp -o index.html -s USE_WEBGPU=1 -s EXPORTED_FUNCTIONS="['_main']" -s FORCE_FILESYSTEM=1`