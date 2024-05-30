#include "webgpu.h"
#include <emscripten.h>
#include <emscripten/html5.h>
#include <iostream>

void initializeWebGPU() {
    // Your WebGPU initialization code here
    std::cout << "WebGPU initialized" << std::endl;
}

int main() {
    initializeWebGPU();
    emscripten_set_main_loop([]() {}, 0, 0); // Keeps the application running
    return 0;
}