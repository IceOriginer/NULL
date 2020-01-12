#include <iostream>
#include "apple.cc"
using namespace std;

const int Apple::apple_number = 30;

Apple::Apple(int i){

}

int Apple::add(int num){
    cout << "non-const add" << endl;
    cout << apple_number << endl;
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
