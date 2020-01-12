#include <iostream>
using namespace std;

class Base{
public:
    inline virtual void who(){
        cout << "I am Base" << endl;
    }

    virtual ~Base(){
        cout << "Decontructor Base" << endl;
    }
};

class Derived : public Base{
public:
    inline void who(){
        cout << "I am Derived" << endl;
    }

    virtual ~Derived(){
        cout << "Deconstructor Derived" << endl;
    }
};


int main(int argc, char *argv[]){
    Base *b = new Base();
    b->who();

    Derived *d = new Derived();
    d->who();
    delete d;  //为了防止内存泄漏，会写执行派生类的析构函数，再执行基类的析构函数

    return 0;
}