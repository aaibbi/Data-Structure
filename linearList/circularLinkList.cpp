//
// Created by liqin on 24-9-24.
//
#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    explicit Node(T value):data(value),next(nullptr){}

};


template<typename T>
class [[maybe_unused]] circularLinkList {

private:
    Node<T>* head;
public:
    circularLinkList():head(nullptr) {}
    void append(T value){
        auto* newNode = new Node<T>(value);
        if(!head) {
            head = newNode;
            newNode->next = head;
        }else{
            Node<T>* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    void display() {
        if(!head) {
            cout << "The Linked List is empty." << endl;
            return;
        }else{
            Node<T>* temp = head;
            do {
                cout << temp->next->data << " ";
                temp = temp->next;
            } while(temp != head);
            cout << endl;

        }
    }
    void remove(T value) {
        if (!head) {
            return;
        }
        Node<T>* current = head;
        Node<T>* previous = nullptr;
        do {
            if (current->data == value) {
                if (current == head) {
                    if (head->next == head) {
                        delete current;
                     head = nullptr;
                    }else {
                        previous = head;
                        while (previous->next != head) {
                            previous = previous->next;
                        }
                        previous->next = head->next;
                        Node<T>* temp = head;
                        head = head->next;
                        delete temp;
                    }
                }else {
                    previous->next = current ->next;
                    delete current;
                }
                return;
            }

            previous = current;
            current = current->next;


        }while(current != head);

    }
     ~circularLinkList() {
        if (!head) {
            return;
        }
        Node<T>* temp = head;
        do {
            Node<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != nullptr);
        head = nullptr;
    }


};
int main() {
    circularLinkList<int> list1;
    list1.append(10);
    list1.append(49);
    list1.append(37);
    list1.display();
    list1.remove(49);
    list1.display();
}
