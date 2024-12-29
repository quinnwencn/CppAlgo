#include <stdexcept>
#include <iostream>

#include "ch1/uf/weighted_quick_union_uf.h"

namespace Algo {

class Ex1_5_13: public WeightedQuickUnionUF {
public:
    Ex1_5_13(uint32_t N): WeightedQuickUnionUF(N), verbose_(true) {}
    ~Ex1_5_13() = default;

    void SetVerbose(bool val) { verbose_ = val; }
    int Root(int site) {
        if (site >= id_.size()) {
            throw std::out_of_range("Index out of range!");
        }

        int root = site;
        while (id_[root] != root) {
            root = id_[root];
        } 

        // while (id_[site] != site) {
        //     int temp = id_[site];
        //     id_[site] = root;
        //     site = temp;
        // }

        return root;
    }

    void Union(int p, int q) {
        int pRoot = Root(p);
        int qRoot = Root(q);

        if (pRoot == qRoot) {
            return;
        }

        if (verbose_) {
            std::cout << "Pair: " << p << "-" << q << std::endl;
            std::cout << "Index: 0 1 2 3 4 5 6 7 8 9" << std::endl;
        }

        int root = qRoot;
        if (sz_[pRoot] < sz_[qRoot]) {
            id_[pRoot] = qRoot;
            sz_[qRoot] += sz_[pRoot];
        } else {
            id_[qRoot] = pRoot;
            sz_[pRoot] += sz_[qRoot];
            root = pRoot;
        }
        count_--;

        while (id_[p] != p) {
            int temp = id_[p];
            id_[p] = root;
            p = temp;
        }

        while (id_[q] != q) {
            int temp = id_[q];
            id_[q] = root;
            q = temp;
        }

        if (verbose_) {
            std::cout << "Array: ";
            for (auto i: id_) {
                std::cout << i << " ";
            }
            std::cout << std::endl;

            std::cout << "Sz: ";
            for (auto i: sz_) {
                std::cout << i << " ";
            }
            std::cout << std::endl;

            std::cout << "Count: " << Count() << std::endl;
            std::cout << std::endl;
        }
    }

private:
    bool verbose_;
};

}

int main(int argc, char** argv) {
    Algo::Ex1_5_13 ex(10);

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
