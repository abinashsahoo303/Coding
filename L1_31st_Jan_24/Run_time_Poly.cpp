#include<iostream>

using namespace std;

class sample{
    public:
    sample(int t1){
        cout << "Constructor called\n";
        x = t1;
    }
    ~sample(){
        cout << "Destructor called\n";
    }
    int getx();
    virtual void callf(){
        cout << "callf called from Sample\n";
    }
    private:
    int x;
};

class Child1:public sample{
    public:
    Child1(int t1):sample(t1){
        cout << "Child Constructor called\n";
    }
    ~Child1(){
        cout << "Child Destructor called\n";
    }    
    virtual void callf(){
        cout << "callf called from Child\n";
    }
    private:
};

int sample::getx(){
    return x;
}

int main(int argc, char **argv){
    int tmp1;
    if(argc == 2){
        tmp1 = atoi(argv[1]);    
    }
    Child1 obj1(tmp1);
    cout << "Object val is : " << obj1.getx() << endl;
    obj1.callf();
}