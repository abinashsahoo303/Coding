#include <iostream>
#include <memory>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base class constructor" << endl;
    }
    virtual ~Base()
    {
        cout << "Base class Destructor" << endl;
    }
    Base(Base &) = delete;
    void operator=(Base &obj) = delete;
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived class constructor" << endl;
    }
    ~Derived()
    {
        cout << "Derived class Destructor" << endl;
    }
};

class singleton
{
    singleton() {}
    static singleton *instance;

public:
    singleton(singleton&) =delete;
    void operator=(singleton&) = delete;
    static singleton *getinstance()
    {
        if (instance == NULL)
        {
            instance = new singleton();
            cout << "Creating an instance" << endl;
            return instance;
        }
        else
        {
            cout << "Returning an instance" << endl;
            return instance;
        }
    }
};

singleton *singleton ::instance = NULL;

int main()
{
    std::unique_ptr<Base> ptr(new Derived);
    singleton *sptr = singleton ::getinstance();
    cout<< "Address of sptr: " << sptr << endl;
    singleton *testobj = singleton ::getinstance();
    cout<< "Address of testobj: " << sptr << endl;
    return 0;
}