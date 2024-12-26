#include <exception>
#include <stdexcept>
#include <iostream>

#include <ch1/uf/quick_find_uf.h>

namespace Algo {

class Ex1_5_1: public QuickFindUF {
public:
    Ex1_5_1(uint32_t N) : QuickFindUF(N), accessTimes_(0), verbose_(false) {}
    ~Ex1_5_1() = default;

    void SetVerbose(bool val) { verbose_ = val; }

    virtual int Root(int p) final {
        if (p >= id_.size()) {
            throw std::out_of_range("Index out of range!");
        }

        accessTimes_++;
        return id_[p];
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
                accessTimes_++;
            }
            accessTimes_++;
        }
        count_--;

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
    Algo::Ex1_5_1 ex(10);
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
