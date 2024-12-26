#include <execution>
#include <stdexcept>
#include <iostream>

#include <ch1/uf/weighted_quick_union_uf.h>

namespace Algo {

class Ex1_5_3: public WeightedQuickUnionUF {
public:
    Ex1_5_3(uint32_t N): WeightedQuickUnionUF(N), accessTimes_(0), verbose_(false) {
        for (uint32_t i = 0; i < N; i++) {
            sz_[i] = 1;
        }
    }

    ~Ex1_5_3() = default;

    void SetVerbose(bool val) { verbose_ = val; }

    virtual int Root(int p) {
        while (p != id_[p]) {
            p = id_[p];
            accessTimes_ += 2;
        }

        accessTimes_++;
        return p;
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

        accessTimes_ += 5;

        if (verbose_) {
            std::cout << "Pair: " << p << "-" << q << std::endl;
            std::cout << "Index = 0 1 2 3 4 5 6 7 8 9" << std::endl;
            std::cout << "Array = ";
            for (auto i = 0; i < id_.size(); i++) {
                std::cout << id_[i] << ' ';
            }
            std::cout << std::endl;
            std::cout << "Access times of array: " << accessTimes_ << std::endl;
            std::cout << std::endl;
        }
        accessTimes_ = 0;
    }

 private:
    uint32_t accessTimes_;
    bool verbose_;
};

}

int main(int argc, char** argv) {
    Algo::Ex1_5_3 ex(10);
    ex.SetVerbose(true);

    ex.Union(9, 0);
    ex.Union(3, 4);
    ex.Union(5, 8);
    ex.Union(7, 2);
    ex.Union(2, 1);
    ex.Union(5, 7);
    ex.Union(0, 3);
    ex.Union(4, 2);

    std::cout << "Site Number: " << ex.Count() << std::endl;

    return 0;
}
