#include <iostream>
#include <cstring>
#include "MyStack/MyStack.hpp"

using namespace std;

template <class DATA>
void Multipliers(int n, MyStack<DATA> &stack) {
    int temp_N = abs(n);
    bool flag = false;

    while (temp_N % 2 == 0 && temp_N != 0) {
        if (!flag && n < 0) {
            stack.push(-2);
            flag = true;
        } else {
            stack.push(2);
        }
        temp_N = temp_N / 2;
    }

    for (int i = 3; i <= temp_N; i = i + 2) {
        while (temp_N % i == 0) {
            if (!flag && n < 0) {
                stack.push(i * -1);
                flag = true;
            } else {
                stack.push(i);
            }
            temp_N = temp_N / i;
        }
    }
}

int main() {
    int n = 3690;
    MyStack<int> stack;
    MyStack<int> stack2;
    Multipliers<int>(n, stack);
    cout << n << " = ";
    while (!stack.empty()) {
        cout << stack.top_inf();
        stack2.push(stack.top_inf());
        stack.pop();
        if (!stack.empty()) cout << " * ";
    }
    cout << endl;

    cout << n << " = ";
    while (!stack2.empty()) {
        cout << stack2.top_inf();
        stack2.pop();
        if (!stack2.empty()) cout << " * ";
    }
    cout << endl;

    MyStack<char> stack3;
    stack3.push('d');
    stack3.push('a');
    stack3.push('g');
    stack3.push('g');
    MyStack<char> stack4(stack3);
    MyStack<char> stack5;
    stack5 = stack3;

    cout << stack3 << endl;
    cout << stack4 << endl;
    cout << stack5 << endl;

    return 0;
}
