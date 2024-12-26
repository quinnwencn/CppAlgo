#pragma once
#include <exception>
#include <stdexcept>

#include "uf.h"

namespace Algo {

class QuickUnionUF: public UF {
public:
    QuickUnionUF(uint32_t N) : UF(N) {}
    ~QuickUnionUF() = default;

    virtual int Root(int p) final {
        if (p >= id_.size()) {
            throw std::out_of_range("Index out of range!");
        }

        while (p != id_[p]) {
            p = id_[p];
        }

        return p;
    }

    virtual bool Connected(int p, int q) final {
        return Root(p) == Root(q);
    }

    virtual void Union(int p, int q) final {
        int pRoot = Root(p);
        int qRoot = Root(q);

        if (pRoot == qRoot) {
            return;
        }

        id_[pRoot] = qRoot;
        count_--;
    }
};

}
