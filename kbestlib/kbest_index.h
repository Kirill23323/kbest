#pragma once
#include <vector>
#include "graph.h"
#include "distance.h"
#include "builder.h"

namespace kbest {

class KBestIndex {
public:
    KBestIndex() = default;
    ~KBestIndex() = default;

    void addPoint(const float* data, int id) {
        // заглушка
        (void)data;
        (void)id;
    }

    std::vector<int> searchKnn(const float* query, int k) const {
        (void)query;
        return std::vector<int>(k, -1);
    }
};

} // namespace kbest
