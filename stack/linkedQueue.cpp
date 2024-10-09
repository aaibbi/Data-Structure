//
// Created by liqin on 24-10-8.
//
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class linkedQueue {
private:
    Node* front;
    Node* rear;
public:
    linkedQueue() {
        front = rear = 0;
    }
    ~linkedQueue() {
        while(front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    void enqueue(int value) {
        Node* temp = new Node(value);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    linkedQueue q;
    q.enqueue(49);
    q.enqueue(28);
    q.display();
    q.dequeue();
    q.display();
}
