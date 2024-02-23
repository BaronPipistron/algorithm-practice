#include <iostream>
#include <vector>

template <class _Tp>
std::ostream& operator << (std::ostream& os, const std::vector<_Tp>& vec) {
    for (size_t i = 0; i != vec.size(); ++i) {
        os << vec[i] << " ";
    }

    return os;
}

template <class _Tp>
void insertionSort(std::vector<_Tp>& vec) {
    for (size_t i = 0; i != vec.size(); ++i) {
        size_t j = i;

        while (j > 0 && vec[j - 1] > vec[j]) {
            std::swap(vec[j - 1], vec[j]);
            --j;
        }
    }

    return;    
}

int main() {
    std::vector<int> vec = {4, 19, 2, 50, -34, 5, -43, 54, 9, 3, -10, 34, 52, -33};

    insertionSort(vec);

    std::cout << vec << std::endl;

    return 0;
}