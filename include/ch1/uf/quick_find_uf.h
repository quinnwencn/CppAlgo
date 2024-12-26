#pragma once
#include <exception>
#include <stdexcept>

#include "uf.h"

namespace Algo {

class QuickFindUF: public UF {
public:
    QuickFindUF(uint32_t N) : UF(N) {}
    ~QuickFindUF() = default;

    virtual int Root(int p) {
        if (p >= id_.size()) {
            throw std::out_of_range("Index out of range!");
        }

        return id_[p];
    }

    virtual bool Connected(int p, int q) {
        return Root(p) == Root(q);
    }

    virtual void Union(int p, int q) {
        int pId = Root(p);
        int qId = Root(q);

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
