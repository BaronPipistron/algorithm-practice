/*
Дан массив не отсортированных целых чисел. Написать функцию, которая вернет первое с конца четное число. 
При написании кода используйте принцип стека. Если массив не содержит четного числа возвращать -1.

Примечание: первая строка во вводе - число элементов в массиве
*/

#include <iostream>
#include <vector>

int main() {
    size_t size;
    int num;
    int last_even = -1;

    std::cin >> size;

    for (size_t i = 0; i != size; ++i) {
        std::cin >> num;
        if (num % 2 == 0) {
            last_even = num;
        }
    }

    std::cout << last_even << std::endl;

    return 0;
}

/*
Непонятно почему не принимается тестирующей системой.
Ответ системы запуска
Код ошибки: CR «CR» — программа завершилась с ненулевым кодом

#include <iostream>
#include <vector>

int64_t lastEven(std::vector<int64_t>& arr) {
    while (arr.back()) {
        if (arr.back() % 2 == 0) {
            return arr.back();
        }

        arr.pop_back();
    }

    return -1;
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

    std::cout << lastEven(vec) << std::endl;

    return 0;
}
*/