#include<iostream>
#include<vector>

using namespace std;

class test{
    string str;
    public:
    // Constructor
    test():str("default string"){ cout << "Default Parameterized constructor" << endl;}
    //copy constuctor
    test(const test& obj):str(obj.str){ cout << "copy constructor " << endl;}
    //Move constructor
    test(test&& obj){
        cout << "Move constructor" << endl;
        str=move(obj.str);
    }
    void printv(){
        cout << "string : "<< str << endl;
    }
    ~test(){
        cout << "destructor called" << endl;
    }
};

int main(){
    test obj1;
    test obj2 = std::move(obj1);
    // test obj3(obj2);
    obj1.printv();
    obj2.printv();
    // obj3.printv();
    // vector<test> vecobj;
    // vecobj.push_back(test());
    return 0;
}