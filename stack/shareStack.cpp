//
// Created by liqin on 24-9-28.
//
#include<iostream>
using namespace std;

template <typename T>
class ShareStack {
private:
    int *data;
    int capacity;
    int top1;
    int top2;
public:
    ShareStack(T size):capacity(size),top1(-1),top2(size) {
        data = new T[size];
    }
    ~ShareStack() {
        delete[] data;
    }
    void push1(const T& item) {
        if (top1 + 1 == top2) {
            std :: cout << "Stack 1 is full" << endl;
        }
        data[++top1] = item;
    }
    void push2(const T& item) {
        if (top2 - 1 == top1) {
            std :: cout << "Stack 2 is full" << endl;
        }
        data[--top2] = item;
    }
    void pop1() {
        if (top1 == -1) {
            std :: cout << "Stack1 is empty." << endl;
        }
        --top1;
    }
    void pop2() {
        if (top2 == capacity) {
            std :: cout << "Stack2 is empty." << endl;
        }
        ++top2;
    }
    T top1value() {
        if (top1 == -1) {
            std :: cout << "Stack1 is empty." << endl;
        }
        return data[top1];
    }
    T top2value() {
        if (top2 == capacity) {
            std :: cout << "Stack2 is empty." << endl;
        }
        return data[top2];
    }
    bool isEmpty1() const {
        return top1 == -1;
    }
    bool isEmpty2() const {
        return top2 == capacity;
    }
    int size1() const {
        return top1 + 1;
    }
    int size2() const {
        return capacity -top2;
    }
};

int main() {
    ShareStack<int> stack(10);
    stack.push1(1);
    stack.push1(2);
    stack.push2(9);
    stack.push2(8);

    std::cout << "Top of Stack 1: " << stack.top1value() << std::endl;
    std::cout << "Top of Stack 2: " << stack.top2value() << std::endl;

    stack.pop1();
    stack.pop2();

    std::cout << "Top of Stack 1 after pop: " << stack.top1value() << std::endl;
    std::cout << "Top of Stack 2 after pop: " << stack.top2value() << std::endl;

    return 0;
}
