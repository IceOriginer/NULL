#include <iostream>
using namespace std;

// const int j = 0;

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

int main(int argc, char *argv[]){
    // char b = 'b';
    // char *c = &b;
    // char const *a = c;
    // char d = 'd';
    // char *e = &d;
    // a = e;
    // *a = 'f';  //error
    // cout << *a << endl;

    // char b = 'b';
    // char *const a = &b;
    // *a = 'a';
    // char c = 'c';
    // // a = &c;  //error
    // cout << *a << endl;

    // char b = 'b';
    // const char *const a = &b;
    // // *a = 'c'; //error
    // // char c = 'c';
    // // a = &c;  // error
    // cout << *a << endl;

    // const int i = 0;

    // const int p = 10;
    // // void *vp = &p;
    // const void *vp = &p;
    // cout << *(int *)vp <<endl;

    // const int *ptr;
    // int val = 3;
    // ptr = &val;
    // // *ptr = 4;
    // val = 5;
    // cout << *ptr <<endl;

    // int num = 0;
    // int *const ptr = &num;
    // num = 1;
    // cout << *ptr << endl;

    // const int num = 1;
    // // int *const ptr = &num;
    // // const int *ptr = &num;
    // const int *const ptr = &num;
    // cout << *ptr << endl;

    Apple apple(10);
    return 0;
}