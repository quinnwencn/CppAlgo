#pragma once
#include <cstdint>
#include <vector>

namespace Algo {

class UF {
public:
    UF(uint32_t N): id_(N, 0), count_(N) {
        for (uint32_t i = 0; i < N; i++) {
            id_[i] = i;
        }
    }

    virtual ~UF() = default;

    uint32_t Count() const { return count_; }
    virtual int Root(int p) = 0;
    virtual bool Connected(int p, int q) = 0;
    virtual void Union(int p, int q) = 0;

protected:
    std::vector<int> id_;
    uint32_t count_;
};

}
