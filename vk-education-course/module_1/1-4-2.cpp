/*
Представьте, что у вас есть электронная библиотека, содержащая информацию о книгах. 
Каждая книга имеет уникальный номер ISBN, название и год издания.

Вам нужно написать программу, которая сортирует все книги по году издания в порядке возрастания. 
Если две или более книг были изданы в один и тот же год, сортируйте их по названию в алфавитном порядке. 
Используйте сортировку слиянием для решения этой задачи.
*/

#include <iostream>
#include <limits>
#include <vector>
#include <string>

struct Book {
    size_t _ISBN { 0 };
    std::string _name { "" };
    int _year_of_publication { 0 };
};

std::istream& operator >> (std::istream& is, Book& book) {
    is >> book._ISBN;

    is.ignore(std::numeric_limits<std::streamsize>::max(), '\"'); 
    std::getline(is, book._name, '\"'); 
    is.ignore();

    is >> book._year_of_publication;

    return is;
}


std::ostream& operator << (std::ostream& os, const Book& book) {
    os << book._ISBN << " \"" << book._name << "\" " << book._year_of_publication << std::endl;

    return os;
}

bool operator <= (const Book& lhs, const Book& rhs) {
    if (lhs._year_of_publication == rhs._year_of_publication) {
        return lhs._name <= rhs._name;
    }

    return lhs._year_of_publication <= rhs._year_of_publication;
}

template <class _Tp>
void merge(std::vector<_Tp>& target_arr, const std::vector<_Tp>& left, 
                                         const std::vector<_Tp>& right) {
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

template <class _Tp>
void mergeSort(std::vector<_Tp>& arr) {
    if (arr.size() == 1) return;

    size_t mid = arr.size() / 2;

    std::vector<_Tp> left_arr;
    std::vector<_Tp> right_arr;

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
    size_t number_of_books;
    std::vector<Book> vec;
    Book book;

    std::cin >> number_of_books;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (size_t i = 0; i != number_of_books; ++i) {
        std::cin >> book;
        
        vec.push_back(book);
    }

    mergeSort(vec);

    for (size_t i = 0; i != number_of_books; ++i) {
        std::cout << vec[i];
    }

    return 0;
}