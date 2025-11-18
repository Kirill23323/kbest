#include <iostream>

#include "kbestlib/kbest_index.h"
#include "kbestlib/graph.h"
#include "kbestlib/distance.h"
#include "kbestlib/utils.h"
#include "kbestlib/prefetch.h"
#include "kbestlib/reorder.h"
#include "kbestlib/early_terminate.h"
#include "kbestlib/simd_neon.h"
#include "kbestlib/quantization.h"
#include "kbestlib/builder.h"

int main() {
    using namespace kbest;

    KBestIndex index;
    Graph graph;
    graph.resize(10);

    float vec[4] = {0, 1, 2, 3};
    index.addPoint(vec, 0);
    index.searchKnn(vec, 5);

    dummy_util();
    prefetch(vec);
    earlyTerminateCheck(123);
    neon_dot(vec, vec, 4);

    Quantizer q;
    q.train(vec, 1, 4);

    GraphBuilder builder;
    builder.build(graph);

    reorder_graph();

    std::cout << "All headers included and project compiled successfully.\n";

    return 0;
}
