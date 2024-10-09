//
// Created by liqin on 24-9-29.
//
#include<iostream>
#include<vector>
#include<string>
#include "Stack.cpp"
using namespace std;
void moveDisk(Stack<int>& source, Stack<int>& destination, const string& sourceName, const string& destinationName) {
    int disk = source.top();
    source.pop();
    destination.push(disk);
    cout << "Nove disk" << disk << "from" <<sourceName << "to" << destinationName << endl;
}
void hanoi(int n, Stack<int>& source, Stack<int>& auxiliary, Stack<int>& destination, const string& sourceName, const string& auxiliaryName, const string& destinationName) {
    if (n == 1) {
        moveDisk(source, destination, sourceName, destinationName);
        return;
    }
    hanoi(n-1, source, destination, auxiliary, sourceName, destinationName, auxiliaryName);
    moveDisk(source, destination, sourceName, destinationName);
    hanoi(n-1,auxiliary, source, destination, auxiliaryName, sourceName, destinationName);
}
int main() {
    int n = 2; // 盘子的数量
    Stack<int> source, auxiliary, destination;

    // 初始化源柱子
    for (int i = n; i >= 1; --i) {
        source.push(i);
    }

    hanoi(n, source, auxiliary, destination, "A", "B", "C");

    return 0;
}



