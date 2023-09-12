#include<iostream>
#include<vector>

using namespace std;

class test{
    int a=5;
    

    public:
    test(){
        cout << "Default constructor is called" << endl;
    }
    int *b=NULL;
    test(int temp,int temp2):a(temp),b(new int(temp2)){
        cout << "Parameterized constructor is called" << endl;
    }
    void print(){
        cout << "Val of test obj is " << a << " " << *b <<endl;
    }
    // copy constructor
    test(const test& obj){
        cout << "copy constructor with deep copy" << endl;
        a = obj.a;
        b = new int;
        *b = *(obj.b);
    }
    // assignment operator overloading
    test& operator=(const test& obj){
        cout << "Operator overloading with deep copy" << endl;
        a = obj.a;
        b = new int;
        *b = *(obj.b);
        return *this;
    }
    // Move constructor
    test(test&& obj){
        cout << "Move constructor is called" << endl;
        a=obj.a;
        b=obj.b;
        obj.b = NULL;
    }

    ~test(){
        if(b != nullptr){
            cout << "Destrcutor is called without nullptr" << endl;
            delete b;
        }
        else{
            cout << "Destrcutor is called with nullptr" << endl;
        }
    }   
};

int main(){
    test obj1(2,3);
    test obj2(obj1);
    // test obj2=obj1; // This invokes copy constructor
    // obj2 = obj1; // This invokes = opertor overloading
    obj2.print();
    if(obj1.b == obj2.b){
        cout << "Sharing the memory location" << endl;
    }
    else{
        cout << "Memory location are not same" << endl;
    }




    std::vector<test> vecobj;
    vecobj.push_back(test(4,7));
}