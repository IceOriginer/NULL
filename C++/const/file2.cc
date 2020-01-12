#include <iostream>
using namespace std;

// int ext;
//如果要访问file1中的非常量ext，需要加上extern，并且file1中的ext可以不需要初始化

extern const int ext;
//如果要访问
int main(int argc, char *argv[]){
    // ext = 14;
    cout << ext + 10 << endl;
    return 0;
}
