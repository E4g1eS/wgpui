# wgpui

Setup:

`sudo apt install emscripten`

To compile:

`emcc main.cpp -o index.html -s USE_WEBGPU=1 -s EXPORTED_FUNCTIONS="['_main']" -s FORCE_FILESYSTEM=1`

To serve:

`emrun --no_browser --port 8080 .`