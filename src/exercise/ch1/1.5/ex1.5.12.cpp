#include <execution>
#include <stdexcept>
#include <iostream>

#include <ch1/uf/quick_union_uf.h>

namespace Algo {

class Ex1_5_12: public QuickUnionUF {
public:
    Ex1_5_12(uint32_t N): QuickUnionUF(N), accessTimes_(0), verbose_(false) {}

    ~Ex1_5_12() = default;

    void SetVerbose(bool val) { verbose_ = val; }

    virtual int Root(int site) {
        int root = site;
        while (root != id_[root]) {
            root = id_[root];
            accessTimes_ += 2;
        }

        accessTimes_++;
        return root;
    }

    virtual void Union(int p, int q) {
        auto pRoot = Root(p);
        auto qRoot = Root(q);

        if (pRoot == qRoot) {
            return;
        }

        id_[p] = qRoot;
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
            std::cout << "Site Number: " << Count() << std::endl;
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
    Algo::Ex1_5_12 ex(10);
    ex.SetVerbose(true);

    ex.Union(9, 0);
    ex.Union(3, 4);
    ex.Union(5, 8);
    ex.Union(7, 2);
    ex.Union(2, 1);
    ex.Union(5, 7);
    ex.Union(0, 3);
    ex.Union(4, 2);
    ex.Union(1, 8);

    return 0;
}
