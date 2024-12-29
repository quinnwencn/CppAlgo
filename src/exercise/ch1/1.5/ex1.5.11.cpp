#include <exception>
#include <stdexcept>
#include <iostream>

#include "ch1/uf/uf.h"

namespace Algo {

class WeightedQuickFindUF: public UF {
public:
    WeightedQuickFindUF(uint32_t N) : UF(N), sz_(N, 1), verbose_(true) {}
    ~WeightedQuickFindUF() = default;

    void SetVerbose(bool val) {verbose_ = val;}
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

        int small = 0;
        int large = 0;
        if (pId < qId) {
            large = qId;
            small = pId;
        } else {
            large = pId;
            small = qId;
        }

        for (auto i = 0; i < id_.size(); i++) {
            if (id_[i] == small) {
                id_[i] = large;
                sz_[large]++;
                sz_[small]--;
            }
        }

        count_--;

        if (verbose_) {
            std::cout << "Pair: " << p << "-" << q << std::endl;
            std::cout << "Array: ";
            for (auto i = 0; i < id_.size(); i++) {
                std::cout << id_[i] << ' ';
            }
            std::cout << std::endl;

            std::cout << "Sz: ";
            for (auto i = 0; i < sz_.size(); i++) {
                std::cout << sz_[i] << ' ';
            }
            std::cout << std::endl;

            std::cout << "Count: " << count_ << std::endl;
        }
    }

private:
    std::vector<int> sz_;
    bool verbose_;
};

}

int main(int argc, char** argv) {
    Algo::WeightedQuickFindUF ex(10);

    ex.Union(9, 0);
    ex.Union(3, 4);
    ex.Union(5, 8);
    ex.Union(7, 2);
    ex.Union(2, 1);
    ex.Union(5, 7);
    ex.Union(0, 3);
    ex.Union(4, 2);

    return 0;
}
