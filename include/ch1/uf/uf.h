#pragma once
#include <cstdint>
#include <vector>

namespace Algo {

class UF {
public:
    UF(uint32_t N): id_(N, 0), count_(N) {
        for (auto i = 0; i < N; i++) {
            id_[i] = i;
        }
    }

    virtual ~UF() = default;

    uint32_t count() const { return count_; }
    virtual int root(int p) = 0;
    virtual bool connected(int p, int q) = 0;
    virtual void union(int p, int q) = 0;

protected:
    std::vector<int> id_;
    uint32_t count_;
};

}
