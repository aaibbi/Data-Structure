//
// Created by liqin on 24-9-28.
//
#include <iostream>
#include <vector>
#include <mmcobj.h>

using namespace std;
template<typename T>
class Stack {
private:
    std :: vector<T> elements;
public:
    void push(const T& item) {
        elements.push_back(item);
    }
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            std :: cout << "Stack is empty" << std :: endl;
        }
    }
    T top() const {
        if (!elements.empty()) {
            return elements.back();
        } else {
            std :: cout << "Stack is empty,no top element." << endl;
            return T();
        }
    }
    bool isEmpty() {
        return elements.empty();
    }
    [[nodiscard]] size_t size() const {
        return elements.size();
    }
};

