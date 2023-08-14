#include<iostream>
#include<memory>

using namespace std;

class Base{
    public:
    Base(){
        cout << "Base class constructor" << endl;
    }
    virtual ~Base(){
        cout << "Base class Destructor" << endl;
    }
    Base(Base&)= delete;
    void operator=(Base& obj)=delete;
};

class Derived: public Base{
    public:
    Derived(){
        cout << "Derived class constructor" << endl;
    }
    ~Derived(){
        cout << "Derived class Destructor" << endl;
    }
};


class singleton{
    singleton(){}
    static singleton *instance;
    public:
    static singleton* getinstance(){
        if(instance = nullptr){
            instance = new singleton();
            return instance;
        }
        else{
            return instance;
        }
    }
};

singleton* singleton::instance = nullptr;

int main(){
    std::unique_ptr<Base> ptr(new Derived);
    singleton *sptr = singleton ::getinstance();
    return 0;
}