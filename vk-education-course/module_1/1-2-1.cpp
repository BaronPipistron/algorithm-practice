/*
На вход подается не отсортированный массив целых чисел и некоторое целое число «element».
Необходимо написать функцию, которая вернет количество элементов, которые не равны данному числу «element».
Возвращаемое значение после работы функции обозначает количество чисел не равные «element».
*/

#include <iostream>
#include <vector>

int main() {
    size_t size;
    int64_t num;
    std::vector<int64_t> vec;

    std::cin >> size;

    for (size_t i = 0; i != size; ++i) {
        std::cin >> num;
        vec.push_back(num);
    }
    
    int64_t element;
    uint64_t result { 0 };

    std::cin >> element;

    for (size_t i = 0; i != size; ++i) {
        if (vec[i] != element) ++result;
    }

    std::cout << result;

    return 0;
}
