#pragma once
#include <exception>

#include "uf.h"

namespace Algo {

class QuickFindUF: public UF {
    QuickFindUF(uint32_t N) : UF(N) {}
    ~QuickFindUF() = default;

    virtual int root(int p) final {
        if (p >= id_.size()) {
            throw std::out_of_range("Index out of range!");
        }

        return id_[p];
    }

    virtual bool connected(int p, int q) final {
        return root(p) == root(q);
    }

    virtual void union(int p, int q) final {
        int pId = root(p);
        int qId = root(q);

        if (pId == qId) {
            return;
        }

        for (auto i = 0; i < id_.size(); i++) {
            if (id_[i] == pId) {
                id_[i] = qId;
            }
        }

        count_--;
    }
};

}
