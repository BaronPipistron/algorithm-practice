/*
Дан массив не отсортированных целых чисел. Написать функцию, которая вернет первое с конца четное число. 
При написании кода используйте принцип стека. Если массив не содержит четного числа возвращать -1.

Примечание: первая строка во вводе - число элементов в массиве
*/

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

/*
Непонятно почему не принимается тестирующей системой.
Ответ системы запуска
Код ошибки: CR «CR» — программа завершилась с ненулевым кодом

int64_t lastEven(std::vector<int64_t>& arr) {
    if (arr.size() == 0) return -1;

    if (arr.back() % 2 == 0) {
        return arr.back();
    }

    arr.pop_back();
    lastEven(arr);
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