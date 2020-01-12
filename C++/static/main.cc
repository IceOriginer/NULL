#include <iostream>
using namespace std;

class Apple{
public:
    static int i;
    int j = 0;
    Apple(){
        cout << "constructor" << endl;
    }

    ~Apple(){
        cout << "destructor" << endl;
    }

    static void print(){
        cout << i << endl;
        // cout << j << endl;
    }
    
    void another(){
        cout << i << endl;
        cout << j << endl;
    }
};

int Apple::i = 1;

void demo(){
    static int count = 0;
    cout << count << " " << endl;
    count++;
}

int main(int argc, char *argv[]){
    // for(int i = 0; i < 5; i++)
    //     demo();

    // Apple apple1;
    // Apple apple2;
    
    // apple1.i = 2;
    // apple2.i = 3;
    // cout << apple1.i << " " << apple2.i;

    // if(1){
    //     static Apple apple3;
    // }
    // cout << "end of main" << endl;

    // apple1.print();
    // apple1.another();
    


    return 0;
}