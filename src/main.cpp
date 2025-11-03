#include "include/host_functions.h"
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    const int n = 1000000;
    std::vector<float> a(n), b(n), c(n);
    
    for (int i = 0; i < n; i++) {
        a[i] = i;
        b[i] = i * 2.0f;
    }
    
    vectorAdd(a.data(), b.data(), c.data(), n);
    
    bool correct = true;
    for (int i = 0; i < n; i++) {
        if (fabs(c[i] - (a[i] + b[i])) > 1e-5) {
            correct = false;
            break;
        }
    }
    
    std::cout << "Result: " << (correct ? "PASSED" : "FAILED") << std::endl;
    
    return 0;
}