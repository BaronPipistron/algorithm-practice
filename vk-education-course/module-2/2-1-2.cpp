/*
Дана строка s. Строка состоит из английских букв в нижнем регистре.Необходимо из строки удалить все рядом 
стоящие повторяющиеся буквы. Например, в строке xyyx мы должны удалить yy, а после и оставшиеся xx и того 
после должна получиться пустая строка. Или же в строке fqffqzzsd после удаления остануться только fsd. 
Первыми удаляться ff, являющимися третьими и четвертыми символами, затем qq и после уже zz.
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string str;
    std::stack<char> stack;

    std::cin >> str;
    
    stack.push(str[0]);
    for (size_t i = 1; i != str.length(); ++i) {
        if (stack.top() == str[i]) {
            stack.pop();
        } else {
            stack.push(str[i]);
        }
    }

    str.clear();
    while (!stack.empty()) {
        str.push_back(stack.top());
        stack.pop();
    }

    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;

    return 0;
}