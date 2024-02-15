/*
Реализовать нисходящую сортировку слиянием.
*/

#include <iostream>
#include <vector>

void merge(std::vector<int64_t>& target_arr, const std::vector<int64_t>& left, const std::vector<int64_t>& right) {
    size_t left_min_index = 0;
    size_t right_min_index = 0;

    size_t target_curr_index = 0;

    while (left_min_index < left.size() && right_min_index < right.size()) {
        if (left[left_min_index] <= right[right_min_index]) {
            target_arr[target_curr_index] = left[left_min_index];
            ++left_min_index;
        } else {
            target_arr[target_curr_index] = right[right_min_index];
            ++right_min_index;
        }
        ++target_curr_index;
    }

    while (left_min_index < left.size()) {
        target_arr[target_curr_index] = left[left_min_index];
        ++left_min_index;
        ++target_curr_index;
    }

    while (right_min_index < right.size()) {
        target_arr[target_curr_index] = right[right_min_index];
        ++right_min_index;
        ++target_curr_index;
    }
}

void mergeSort(std::vector<int64_t>& arr) {
    if (arr.size() == 1) return;

    size_t mid = arr.size() / 2;

    std::vector<int64_t> left_arr;
    std::vector<int64_t> right_arr;

    for (size_t i = 0; i != mid; ++i) {
        left_arr.push_back(arr[i]);
    }
    
    for (size_t i = mid; i != arr.size(); ++i) {
        right_arr.push_back(arr[i]);
    }

    mergeSort(left_arr);
    mergeSort(right_arr);
    merge(arr, left_arr, right_arr);
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

    mergeSort(vec);

    for (size_t i = 0; i != size; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}