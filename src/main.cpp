#include <iostream>
#include <vector>

void vectorAdd(const float* h_a, const float* h_b, float* h_c, int n);

int main() {
    const int n = 1000000;
    std::vector<float> a(n), b(n), c(n);
    
    // Initialize vectors
    for (int i = 0; i < n; i++) {
        a[i] = i;
        b[i] = i * 2.0f;
    }
    
    // Perform vector addition
    vectorAdd(a.data(), b.data(), c.data(), n);
    
    // Verify results
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