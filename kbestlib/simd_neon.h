#pragma once

namespace kbest {

// stub SIMD function
inline float neon_dot(const float* a, const float* b, int dim) {
    (void)a; (void)b; (void)dim;
    return 0.0f;
}

} // namespace kbest
