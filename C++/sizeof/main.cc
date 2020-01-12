#include <iostream>
using namespace std;

class A{
};

class B{
public:
    char a;
    char aa; 
    long e;
    virtual void fun1(){}
    static int b;
    int c;
    void func2(){}
    static void func3(){}
};

class C{
public:
    virtual void func1(){}
    virtual void func2(){}
    virtual void func3(){}
};

class D{
public:
    char a; // 长为1，补3，变成4
    int b; // 长为4
    char aa;  //长为1
    char aaa;  //长为1，aa和aaa放在一起，再补2

};

class E:D{
public:
    // 继承D中的，不过由于最长的是4个，所以E占用8个字节，D占用12个字节
    short a;
    int b;

};

class D1{

virtual void fun1(){}
virtual void fun2(){}
virtual void fun3(){}

};
    


class E1:D1{

};

class F{
    virtual void func1(){}
};

class G{
    virtual void func2(){}
};

class H : virtual public F, virtual public G {
    virtual void func3(){}
};

int main(int argc, char *argv[]){
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;

    cout << sizeof(D) << endl;
    cout << sizeof(E) << endl;

    cout << sizeof(D1) << endl;
    cout << sizeof(E1) << endl;  //只继承了一个vptr

    cout << sizeof(H) << endl;

}