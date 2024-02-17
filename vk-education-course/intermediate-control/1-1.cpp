/*
Дан не отсортированный массив целых чисел. Необходимо перенести в начало массива все четные числа. 
При этом последовательность четных чисел должна быть сохранена. То есть если 8 стояла после 6, 
то после переноса в начало, она по-прежнему должна стоять после 6.
*/

#include <iostream>
#include <vector>

template <class _Tp>
void evenToFront(std::vector<_Tp>& arr) {
    size_t last_even_index = 0;
    size_t curr_index = 0;
    
    while (curr_index < arr.size()) {
        if (arr[curr_index] % 2 == 0) {
            std::swap(arr[last_even_index++], arr[curr_index]);
        }

        ++curr_index;
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

    evenToFront(vec);

    for (size_t i = 0; i != size; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}