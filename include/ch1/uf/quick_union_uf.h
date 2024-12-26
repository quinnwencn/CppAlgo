#pragma once
#include <exception>

#include "uf.h"

namespace Algo {

class QuickUnionUF: public UF {
    QuickUnionUF(uint32_t N) : UF(N) {}
    ~QuickUnionUF() = default;

    virtual int root(int p) final {
        if (p >= id_.size()) {
            throw std::out_of_range("Index out of range!");
        }

        while (p != id_[p]) {
            p = id_[p];
        }

        return p;
    }

    virtual bool connected(int p, int q) final {
        return root(p) == root(q);
    }

    virtual void union(int p, int q) final {
        int pRoot = root(p);
        int qRoot = root(q);

        if (pRoot == qRoot) {
            return;
        }

        id_[pRoot] = qRoot;
        count_--;
    }
};

}
