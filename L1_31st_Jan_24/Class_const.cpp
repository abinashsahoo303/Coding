#include<iostream>

using namespace std;

class A{
    public:
    A(int t1){
        cout << "Constructor called\n";
        x = t1;
    }
    ~A(){
        cout << "Destructor called\n";
    }
    int getx();
    private:
    int x;
};

int A::getx(){
    return x;
}

int main(int argc, char **argv){
    int tmp1;
    if(argc == 2){
        tmp1 = atoi(argv[1]);    
    }
    A obj1(tmp1);
    cout << "Object val is : " << obj1.getx() << endl;
}