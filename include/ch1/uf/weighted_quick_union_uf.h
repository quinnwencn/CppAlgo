#pragma once
#include <execution>
#include <stdexcept>

#include "uf.h"

namespace Algo {

class WeightedQuickUnionUF: public UF {
public:
    WeightedQuickUnionUF(uint32_t N): UF(N), sz_(N, 0) {
        for (uint32_t i = 0; i < N; i++) {
            sz_[i] = 1;
        }
    }

    ~WeightedQuickUnionUF() = default;

    virtual int Root(int p) {
        while (p != id_[p]) {
            p = id_[p];
        }

        return p;
    }

    virtual bool Connected(int p, int q) final {
        return Root(p) == Root(q);
    }

    virtual void Union(int p, int q) {
        auto pRoot = Root(p);
        auto qRoot = Root(q);

        if (pRoot == qRoot) {
            return;
        }

        if (sz_[pRoot] < sz_[qRoot]) {
            id_[pRoot] = qRoot;
            sz_[qRoot] += sz_[pRoot];
        } else {
            id_[qRoot] = pRoot;
            sz_[pRoot] += sz_[qRoot];
        }
        count_--;
    }

protected:
    std::vector<int> sz_;
};

}
