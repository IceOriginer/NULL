### 1. const含义
常量类型是指使用类型修饰符const说明的类型，常量类型的变量或对象是不能被修改的。

### 2. const作用
* 可以定义常量
    ```c++
    const int a = 100;
    ```
* 类型检查
const常量与`#define`宏定义常量的区别：const常量具有类型，编译器可以进行安全检查；`#define`宏定义没有数据类型，只是进行简单的字符串替换，不能进行安全检查；
* 防止修改，起保护作用，增加程序健壮性；
* 可以节省内存，避免不必要的内存分配；

const定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像`#define`一样给出的是立即数，所以，const定义的常量在程序运行过程中只有一份拷贝，而`#define`定义的常量在内存中有若干个拷贝。

### 3. const 对象默认为文件局部变量
注意：非const变量默认为extern。要使const变量能够在其它文件中访问，必须在文件中显式指定它为extern；
* 对于非const所修饰变量的访问，在被访问文件中变量的定义可以不需要加上`extern`关键字，也不需要初始化；
* 对于const所修饰变量的访问，在被访问文件中变量的定义需要加上`extern`，否则那个变量只在被定义的那个文件中有效，同时变量定义的时候需要进行初始化。在要访问该变量的文件中最好声明一个`extern const`的变量，如果不加上`const`的话，编译可以通过，但是修改这个变量的时候会出现段错误。

### 4. 定义常量
常量在定义的时候必须初始化，因为常量是不能修改的。

### 5. 指针与const
与指针相关的const有四种：
```c++
const char *a;  //指向const对象的指针或者说指向常量的指针
char const *a;  //同上，指针是可以修改的，但是指针指向的值不能修改
/*
    char b = 'b';
    char *c = &b;
    char const *a = c;
    char d = 'd';
    char *e = &d;
    a = e;
    *a = 'f';  //error
    cout << *a << endl;
*/

char *const a;  //指针是个常量，但是指向的类型不是常量
/*
    // char b = 'b';
    // char *const a = &b;
    // *a = 'a';
    // char c = 'c';
    // // a = &c;  //error
    // cout << *a << endl;
*/
const char *const a;  //指针是常量的，指针指向的类型也是常量的
/*
    // char b = 'b';
    // const char *const a = &b;
    // // *a = 'c'; //error
    // // char c = 'c';
    // // a = &c;  // error
    // cout << *a << endl;
*/
```
**小结：如果`const`位于`*`的左侧，则const就是用来修饰指针所指向的变量，即指针指向常量；如果`const`位于`*`的右侧，则`const`就是修饰指针本身，即该指针是一个常量指针。**

以下是要注意的点：
* 不能使用`void *`指针保存`const`对象的地址，必须使用`const void *`类型的指针保存const对象的地址；
    ```c++
    const int p = 10;
    //void *vp = &p; //error
    const void *vp = &p;
    cout << *(int *)vp <<endl;
    ```
* 允许把非`const`对象的地址赋给指向const对象的指针；
    ```c++
    const int *ptr;  //指向常量的指针可以不初始化，因为该指针不是常量的
    int val = 3;
    ptr = &val;
    // *ptr = 4;  //error，ptr指针是一个指向常量的指针，即使val不是常量，依然不能修改
    cout << *ptr <<endl;

    //由于val不是常量的，所以可以通过其它方式来修改其值，如：val = 5;此时ptr所指向地址的值也修改了，只是不能通过ptr指针来修改而已
    ```
* 常量指针必须初始化，因为它不能再修改；
    ```c++
    int num = 0;
    int *const ptr = &num;
    num = 1;  //指针是常量的，但是指向的值不是常量的，所以可以正常进行修改
    cout << *ptr << endl;
    ```
* 如果所定义的常量指针指向的不是一个常量，然后将一个常量的地址赋给它会出错；
    ```c++
    const int num = 0;
    int *const ptr = &num;  //error,因为ptr只能指向一个非常量。
    const int *ptr = &num;  //right,ptr是一个指向常量的指针
    const int *const ptr = &num;  //right,ptr是一个常量指针且指向常量
    cout << *ptr << endl;
    ```
* 指向常量的指针，以此类推。

### 6. 函数中使用const
> `const`修饰函数返回值，与`const`修饰普通变量以及指针的含义基本相同

* `const int func1();`这个本身没有意义，因为`int`参数返回本身就是赋值给其它的变量；
* `const int* func2();`返回值是一个指针，指针指向的内容不能修改；
* `int *const func3();`返回值是一个指针，并且指针本身不能修改。

> `const`修饰函数参数
* 传递过来的参数及指针本身在函数内不可变；
    ```c++
    void func1(const int var);  //由于int是一个内部数据类型，所以调用func1的时候进行了值拷贝，调用func1时所传入的参数本身就不会在func1中被修改
    void func2(int *const var);  //同理
    //因此这两个地方用的没有意义
    ```
* 参数指针所指内容为常量不可变；
    ```c++
    void StringCopy(char *dst, const char *src);  //可以保证在StringCopy执行过程中src所指向的内容不会发生改变，可以保证程序的健壮性
    ```
* 参数为引用，为了在增加效率的同时防止修改。
    ```c++
    void func(const A &a);
    ```
    对于非内部数据类型的参数而言，像`func(A a)`的调用过程中，编译器会产生一个临时的对象`a`，然后传递给函数之后会将这个临时对象析构掉。在这个过程中出现了对象的构造，复制和析构，这些过程都比较耗时间。因此可以采用引用的方式，给传入的对象起个别名，但是为了防止对象被修改可以使用`const`修饰。
    
    对于内部数据类型，值传递和传递引用的效率几乎相当，所以没必要用引用。
### 7. 类中使用const
在类中，任何不会修改数据成员的函数都应该声明为`const`类型。如果在编写`const`成员函数时，不慎修改了数据成员，或者调用了其它非`const`的成员函数，编译器将报错，因此可以提高程序的健壮性。使用`const`修饰的成员函数成为常量成员函数，只有常量成员函数才能操作常或者常量对象。

以下是主要需要注意的地方：
* 对于类中的`const`成员变量必须通过初始化列表进行初始化；
    ```c++
    class Apple{
    private:
        int people[100];
    public:
        Apple(int i);
        const int apple_number;
    };

    Apple::Apple(int i):apple_number(i){
        cout << apple_number << endl;
    }
    ```
* `const`对象只能访问`const`成员函数，而非`const`对象可以访问任意的成员函数，包括`const`成员函数；
    ```c++
    // apple.cc
    class Apple{
    private:
        int people[100];
    public:
        Apple(int i);
        const int apple_number;
        void take(int num) const;
        int add(int num);
        int add(int num) const;
        int getCount() const;
        void addone();
    };

    // main.cc
    #include <iostream>
    #include "apple.cc"
    using namespace std;

    Apple::Apple(int i):apple_number(i){

    }

    int Apple::add(int num){
        cout << "non-const add" << endl;
        take(num);
    }

    int Apple::add(int num) const{
        cout << "const add" << endl;
        take(num);
    }

    void Apple::take(int num) const{
        cout<<"take func "<< num <<endl;
    }

    int Apple::getCount() const{
        take(1);
        return apple_number;
    }

    void Apple::addone(){
        cout << "add one" << endl;
    }

    int main(int argc, char *argv[]){
        Apple a(2);
        cout<< a.getCount() <<endl;
        a.add(10);
        const Apple b(3);
        b.add(100);
        a.addone();
        // b.addone(); //error
        return 0;
    }
    ```
* `const`与`static`结合;
    ```c++
    //apple.cc
    static const int apple_number; //定义，但是不初始化，Apple的构造函数也不初始化
    
    //main.cc
    const int Apple::apple_number = 30;  //在main函数外面进行初始化
    ```

**在C++中，static静态成员变量不能在类的内部初始化。在类的内部只是声明，定义必须在类定义的外部，通常在类的实现文件中初始化。**









