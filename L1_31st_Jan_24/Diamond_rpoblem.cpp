#include<iostream>

using namespace std;

class sample{
    public:
    sample(){
        cout << "sample Constructor called\n";
        // x = t1;
    }
    virtual ~sample(){
        cout << "sample Destructor called\n";
    }
    // int getx();
    virtual void callf(){
        cout << "callf called from Sample\n";
    }
    private:
    // int x;
};

class Child1:virtual public sample{
    public:
    Child1(){
        cout << "Child1 Constructor called\n";
    }
    virtual ~Child1(){
        cout << "Child1 Destructor called\n";
    }    
    virtual void callf(){
        cout << "callf called from Child1\n";
    }
    private:
};

class Child2:virtual public sample{
    public:
    Child2(){
        cout << "Child2 Constructor called\n";
    }
    virtual ~Child2(){
        cout << "Child2 Destructor called\n";
    }    
    virtual void callf(){
        cout << "callf called from Child2\n";
    }
    private:
};

class Child3:public Child1, Child2{
    public:
    Child3(){
        cout << "Child3 Constructor called\n";
    }
    ~Child3(){
        cout << "Child3 Destructor called\n";
    }    
    virtual void callf(){
        cout << "callf called from Child3\n";
    }
    private:
};

// int sample::getx(){
//     return x;
// }

int main(int argc, char **argv){
    int tmp1;
    if(argc == 2){
        tmp1 = atoi(argv[1]);    
    }
    sample *obj1(new Child3);
    // cout << "Object val is : " << obj1.getx() << endl;
    obj1->callf();
    delete obj1;
}