#include <cuda_runtime.h>
#include <iostream>

extern "C" void launchVectorAdd(const float* d_a, const float* d_b, float* d_c, int n);

void vectorAdd(const float* h_a, const float* h_b, float* h_c, int n) {
    // Allocate device memory
    float *d_a, *d_b, *d_c;
    size_t bytes = n * sizeof(float);
    
    cudaMalloc(&d_a, bytes);
    cudaMalloc(&d_b, bytes);
    cudaMalloc(&d_c, bytes);
    
    // Copy data to device
    cudaMemcpy(d_a, h_a, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, bytes, cudaMemcpyHostToDevice);
    
    // Launch kernel (implemented in .cu file)
    launchVectorAdd(d_a, d_b, d_c, n);
    
    // Copy result back
    cudaMemcpy(h_c, d_c, bytes, cudaMemcpyDeviceToHost);
    
    // Cleanup
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
}