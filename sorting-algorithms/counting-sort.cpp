#include <cassert>
#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
    int max = arr[0];
    size_t size = arr.size();

    for (size_t i = 1; i != size; ++i) {
        max = (max < arr[i]) ? arr[i] : max;
    }

    std::vector<int> helperArr(max, 0);

    for (size_t i = 0; i != size; ++i) {
        ++helperArr[arr[i]];
    }

    int index = 0;
    for (size_t i = 0; i != max + 1; ++i) {
        for (size_t j = 0; j != helperArr[i]; ++j) {
            arr[index++] = i;
        }
    }

    return;
}

int main() {
    std::vector<int> vec = {5, 9, 0, 14, 5, 43, 1, 4, 2};

    countingSort(vec);

    for (size_t i = 0; i != vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}