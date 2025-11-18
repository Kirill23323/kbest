#pragma once
#include <vector>

namespace kbest {

class Graph {
public:
    Graph() = default;
    ~Graph() = default;

    void resize(size_t n) {
        adjacency.resize(n);
    }

    std::vector<std::vector<int>> adjacency;
};

} // namespace kbest
