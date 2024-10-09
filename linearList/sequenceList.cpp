//
// Created by liqin on 24-9-23.
//
#include <iostream>
using namespace std;

const int MAX_SIZE=100;
template<typename T>
class LinearList{
private:
    T data[MAX_SIZE];
    int length;
public:
    LinearList(){
        length=0;
    }
    [[nodiscard]] int getLength() const{
        return length;
    }
    [[nodiscard]] bool isEmpty() const{
        return length==0;
    }
    bool insert(int pos,T value){
        if(pos<0 || pos > length || pos >= MAX_SIZE){
            cout << "插入位置不和法或表已满。" << endl;
        }
        for (int i = length; i > pos ; --i){
            data[i] = data[i-1];
        }
        data[pos] = value;
        length++;
        return true;

    }
    bool remove(int pos){
        if (pos < 0 || pos >= length){
            cout << "删除位置不合法。" << endl;
        }
        for (int i = pos; i < length-1; ++i){
            data[i] = data[i+1];
        }
        length--;
        return true;
    }
    T get(int pos) {
        if (pos < 0 || pos >= length){
            throw out_of_range("索引超出范围");
        }
        return data[pos];
    }
    void display() const {
        for (int i = 0; i < length; i++){
            cout << data[i] << " ";
        }
    }
};
int main() {
    //使用int类型的线性表
    LinearList<int> list1;
    list1.insert(0,10);
    list1.insert(1,20);
    list1.remove(3);
    list1.display();
    //使用float类型操作线性表
    LinearList<float> list2;
    list2.insert(1, 2.2f);
    list2.display();

    return 0;


}

