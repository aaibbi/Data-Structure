//
// Created by liqin on 24-9-24.
//
#include<iostream>
using namespace std;
template<typename T>
class Node {
    T data;
    Node* next;
    Node* prev;
    explicit Node(T value):data(value),next(nullptr),prev(nullptr){}
};
template<typename T>
class doublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    doublyLinkedList():head(nullptr),tail(nullptr){}

    void append(T value) {
        auto* newNode = new Node<T>(value);
        if (!head) {
            head = tail =newNode;
        }else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

    }
    void remove(T value) {

    }
    void display() {

    }

};
