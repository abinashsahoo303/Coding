#include<iostream>

using namespace std;

class Test{};

void func(const Test& test){
    cout<< "Lvalue reference\n";
}

void func(Test&& test){
    cout<< "Rvalue refernce\n";
}

int main(){
    Test test;

    //Arg is test variable
    func(test);

    //Arg is temp object
    func(std::move(test));

}