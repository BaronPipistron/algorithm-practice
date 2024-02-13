/*
Реализовать сортировку вставками (insertion sort)

На вход подаётся массив чисел

На выходе ожидается отсортированный массив чисел
*/

#include <iostream>
#include <vector>

void insertionSort(std::vector<int64_t>& arr) {
    for (size_t i = 1; i != arr.size(); ++i) {
        size_t j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            int64_t tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;

            --j;
        }
    }
}

int main() {
    size_t size;
    int64_t num;
    std::vector<int64_t> vec;

    std::cin >> size;

    for (size_t i = 0; i != size; ++i) {
        std::cin >> num;
        vec.push_back(num);
    }

    insertionSort(vec);

    for (size_t i = 0; i != size; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}