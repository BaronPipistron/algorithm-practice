#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

template <class _Tp>
std::ostream& operator << (std::ostream& os, const std::vector<_Tp>& vec) {
    for (size_t i = 0; i != vec.size(); ++i) {
        os << vec[i] << " ";
    }

    return os;
}

template <class _Tp>
void countingSort(std::vector<_Tp>& vec) {
    _Tp min = *std::min_element(vec.begin(), vec.end());
    _Tp max = *std::max_element(vec.begin(), vec.end());

    _Tp difference = -1 * min;
    size_t size = vec.size();

    if (max > size || std::abs(min) > size) {
        throw std::logic_error("ERROR: MAX_ELEMENT or abs(MIN_ELEMENT) more than SIZE. Choose another sorting algorithm");
    }

    std::vector<uint8_t> counterArr(max + difference + 1, _Tp(0));
    std::vector<_Tp> resArr(size);

    for (size_t i = 0; i != size; ++i) {
        ++counterArr[vec[i] + difference];
    }

    for (size_t i = 1; i != max + difference + 1; ++i) {
        counterArr[i] += counterArr[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        resArr[counterArr[vec[i] + difference] - 1] = vec[i];
        --counterArr[vec[i] + difference];
    }
    vec = resArr;

    return;
}

int main() {
    std::vector<int> vec = {-1, 2, 5, -3, 6, 7, -6, 3, 4, 5, 9, 8, 3, 9, 5};

    countingSort(vec);

    std::cout << vec << std::endl;

    return 0;
}