#ifndef VECADD_KERNEL_H
#define VECADD_KERNEL_H

#ifdef __cplusplus
extern "C" {
#endif

void launchVectorAdd(const float* d_a, const float* d_b, float* d_c, int n);

#ifdef __cplusplus
}
#endif

#endif