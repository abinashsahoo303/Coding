#include<iostream>
#include<memory>


using namespace std;

class sample{
    public:
    sample(){
        cout << "sample Constructor called\n";
    }
    virtual ~sample(){
        cout << "sample Destructor called\n";
    }
    virtual void printfun() = 0; 
    private:
};

class child:public sample{
    public:
    child(){
        cout << "child sample Constructor called\n";
    }
    ~child(){
        cout << "child sample Destructor called\n";
    }
    virtual void printfun(){
        cout << "Child class printfun\n";
    } 
    private:
};

int main(int argc, char **argv){
    int tmp1;
    if(argc == 2){
        tmp1 = atoi(argv[1]);    
    }
    std::unique_ptr<sample> obj(new child);
}