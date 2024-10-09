//
// Created by liqin on 24-9-23.
//
#include<iostream>
using namespace std;
//定义节点结构
struct listNode {
    int data;
    listNode* next;
};
//初始化链表
listNode* linkList() {
    auto* head =  new listNode;
    head->next = nullptr;
    return head;
}
//头插法插入节点
void insert_head(listNode* head, int value) {
    auto* newNode = new listNode();
    newNode->data = value;
    newNode->next = head->next;
    head->next = newNode;

}
//尾插法插入节点
[[maybe_unused]] void insert_tail(listNode* head, int value) {
    auto* newNode = new listNode;
    newNode->data = value;
    newNode->next = nullptr;
    listNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
//删除节点
bool deleteNode(listNode* head, int value) {
    listNode* temp = head;
    while(temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == nullptr){
        return false;
    }
    listNode* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return true;
}
//按位置插入节点
 bool insert_position(listNode* head, int position, int value) {
    if (position<1) {
        return false;
    }
    if (position == 1) {
        insert_head(head,value);
        return true;
    }
    listNode* temp = head;
    for(int i = 1; i < position -1 && temp != nullptr; i++){
        temp = temp->next;
    }
    if (temp == nullptr) {
        return false;
    }
    auto* newNode = new listNode;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    return true;

}
//返回链表长度
int list_length(listNode* head) {
    listNode* temp = head;
    int length = 0;
    if (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}
//判断链表是否为空
bool is_empty(listNode* head) {
    return head == nullptr;
}
//打印链表
void print_list(listNode* head) {
    listNode* temp = head->next;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    listNode* list1 = linkList();
    insert_head(list1, 10);
    insert_head(list1, 20);
    insert_head(list1, 30);

    print_list(list1);


    listNode *list2 = linkList();
    insert_head(list2, 40);
    insert_head(list2, 20);
    insert_head(list2, 30);
    print_list(list2);
}