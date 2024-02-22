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
void merge(std::vector<_Tp>& target_arr, const std::vector<_Tp>& left_arr,
                                         const std::vector<_Tp>& right_arr) {
    size_t left_min_index = 0;
    size_t right_min_index = 0;

    size_t target_curr_index = 0;

    while (left_min_index < left_arr.size() && right_min_index < right_arr.size()) {
        if (left_arr[left_min_index] <= right_arr[right_min_index]) {
            target_arr[target_curr_index++] = left_arr[left_min_index++];
        } else {
            target_arr[target_curr_index++] = right_arr[right_min_index++];
        }
    }

    while (left_min_index < left_arr.size()) {
        target_arr[target_curr_index++] = left_arr[left_min_index++];
    }

    while (right_min_index < right_arr.size()) {
        target_arr[target_curr_index++] = right_arr[right_min_index++];
    }
}

template <class _Tp>
void mergeSort(std::vector<_Tp>& vec) {
    if (vec.size() == 1) return;

    size_t mid = vec.size() / 2;

    std::vector<_Tp> left_arr;
    std::vector<_Tp> right_arr;

    for (size_t i = 0; i != mid; ++i) {
        left_arr.push_back(vec[i]);
    }

    for (size_t i = mid; i != vec.size(); ++i) {
        right_arr.push_back(vec[i]);
    }

    mergeSort(left_arr);
    mergeSort(right_arr);
    merge(vec, left_arr, right_arr);
}

int main() {
    std::vector<int> vec = {4, 19, 2, 50, -34, 5, -43, 54, 9, 3, -10, 34, 52, -33};

    mergeSort(vec);

    std::cout << vec << std::endl;

    return 0;
}