#include "webgpu.h"
#include <emscripten.h>
#include <emscripten/html5.h>
#include <iostream>

WGPUAdapter adapter;
WGPUDevice device;

void initializeWebGPU() {
    // Request the adapter
    WGPURequestAdapterOptions options = {};
    
    wgpuInstanceRequestAdapter(nullptr, &options, [](WGPURequestAdapterStatus status, WGPUAdapter result, const char* message, void* userdata) {
        adapter = result;
    }, nullptr);

    // Request the device
    WGPUDeviceDescriptor deviceDesc = {};
    wgpuAdapterRequestDevice(adapter, &deviceDesc, [](WGPURequestDeviceStatus status, WGPUDevice result, const char* message, void* userdata) {
        device = result;
    }, nullptr);
    std::cout << "WebGPU initialized" << std::endl;
}

int main() {
    initializeWebGPU();
    emscripten_set_main_loop([]() {}, 0, 0); // Keeps the application running
    return 0;
}