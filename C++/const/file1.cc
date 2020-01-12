#include <iostream>
using namespace std;

// int ext;

extern const int ext = 11;
//对于const修饰的ext，要让其它文件可以访问ext，需要加上extern，如果file2中使用一个声明的是一个非const的ext，编译可以通过，但是在file2中不能修改ext，否则会出现段错误

// 最好让file2中的变量也用extern和const同时修饰

