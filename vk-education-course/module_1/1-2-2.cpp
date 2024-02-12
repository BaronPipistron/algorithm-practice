/*
В школе прошел экзамен по математике. Несколько человек списали решения и были замечены. 
Этим школьникам поставил 0 баллов. Задача: есть массив с оценками, среди которых есть 0. 
Необходимо все оценки, равные нулю перенести в конец массива, чтобы все такие школьники оказались в конце списка.

Примечание: первая строка во вводе - число элементов в массиве
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

    std::vector<int64_t> new_vec;
    int64_t zero_counter { 0 };

    for (size_t i = 0; i != size; ++i) {
        if (vec[i] == 0) {
            ++zero_counter;
        } else {
            new_vec.push_back(vec[i]);
        }
    }

    while (zero_counter != 0) {
        new_vec.push_back(0);
        --zero_counter;
    }

    for (size_t i = 0; i != size; ++i) {
        std::cout << new_vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}