### 1. 类中内联
头文件中声明方法，在函数实现的时候加上关键字`inline`。

内联可以提高函数效率，但并不是所有的函数都定义成内联函数。内联是以代码复制作为代价的，仅仅省去了函数调用的开销，从而提高了函数的执行效率，但是代码的可读性受到很大的影响。

* 如果执行函数体内的代码的时间比函数调用的开销较大，那么效率的收获会更少；
* 另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。

以下情况不宜使用内联：
* 如果函数体内的代码比较长，使用内联会导致内存消耗代价比较高；
* 如果函数体内出现循环，那么执行函数体内代码的时间比函数调用的开销大。

### 2. 虚函数可以是内联函数嘛？
* 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数呈现多态性的时候不能内联；
* 内联是编译器在编译期间，如果发生了函数调用，则直接使用内联定义的代码替换掉函数调用的那块代码。如果虚函数呈现多态的特性，多态性只有在运行过程中才会表现出来。因此编译过程中，编译器无法知道运行期会调用什么代码，因此虚函数呈现多态性的时候不能内联；
* `inline virtual`唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如`Base::Who()`），这只有在编译器具有实际对象而不是对象的指针或引用才会发生。

```c++
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
    b->who();  // 运行过程中才能知道调用的who是哪一个，所以不是内联

    Base c;
    c.who();  // 编译过程中c就已经确定了，所以是内联，但是具体有没有执行内联由编译器决定

    Derived *d = new Derived();
    d->who();
    delete d;  //为了防止内存泄漏，会写执行派生类的析构函数，再执行基类的析构函数

    return 0;
}
```