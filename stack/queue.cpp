//
// Created by liqin on 24-10-8.
//
#include<iostream>
using namespace std;

#define Max 1000;

class Queue {
    int front, rear, size;
    int* arr;
public:
    explicit Queue(int s) {
        front = rear = 0;
        size = s;
        arr = new int[s];
    }
    ~Queue() {
        delete[] arr;
    }
    void enqueue(int value) {
        if(size == rear) {
            cout << "Queue is full\n";
            return;
        }else {
            arr[rear] = value;
            rear++;
        }
           }
    void dequeue() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        }else {
            for (int i = 0; i < rear -1; i++) {
                arr[i] = arr[i + 1];
            }
            rear--;
        }
           }
    void display() {
        if (front == rear) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
   }
};

int main() {
    Queue q(1000);
    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(49);
    q.display();
}