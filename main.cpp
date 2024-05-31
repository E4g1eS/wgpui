#include <webgpu/webgpu.h>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <iostream>

// Global variables for WGPUAdapter and WGPUDevice
WGPUAdapter adapter = nullptr;
WGPUDevice device = nullptr;

// Callback function for adapter request
void onAdapterRequest(WGPURequestAdapterStatus status, WGPUAdapter result, const char* message, void* userdata) {
    if (status == WGPURequestAdapterStatus_Success) {
        adapter = result;
        std::cout << "Adapter request succeeded" << std::endl;

        // Now request the device
        WGPUDeviceDescriptor deviceDesc = {};
        wgpuAdapterRequestDevice(adapter, &deviceDesc, [](WGPURequestDeviceStatus status, WGPUDevice result, const char* message, void* userdata) {
            if (status == WGPURequestDeviceStatus_Success) {
                device = result;
                std::cout << "Device request succeeded" << std::endl;
            } else {
                std::cerr << "Device request failed: " << message << std::endl;
            }
        }, nullptr);
    } else {
        std::cerr << "Adapter request failed: " << message << std::endl;
    }
}

void initializeWebGPU() {
    WGPURequestAdapterOptions options = {};
    wgpuInstanceRequestAdapter(nullptr, &options, onAdapterRequest, nullptr);
}

int main() {
    initializeWebGPU();
    emscripten_set_main_loop([]() {}, 0, 0); // Keeps the application running
    return 0;
}