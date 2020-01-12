#include <iostream>
using namespace std;

class A{
public:
    const int SIZE;
    A(int size);  // 构造函数
};

A::A(int size) : SIZE(size){  // 构造函数的实现

}

class Person{
public:
    // typedef enum{
    //     BOY=3,
    //     GIRL
    // }Sex;
};

int main(int argc, char *argv[]){
    // A a(100);
    // A b(200);
    // cout << a.SIZE << endl;
    // cout << b.SIZE << endl;

    // cout << Person::BOY << endl;
    // cout << Person::GIRL << endl;
    // Person boy;
    // cout << boy.BOY << endl;
    // cout << boy.GIRL << endl;

    cout << sizeof(Person) << endl;
    return 0;
}