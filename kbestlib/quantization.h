#pragma once
#include <vector>

namespace kbest {

class Quantizer {
public:
    Quantizer() = default;

    void train(const float* data, size_t n, size_t dim) {
        (void)data; (void)n; (void)dim;
    }
};

} // namespace kbest
