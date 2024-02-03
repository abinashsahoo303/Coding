#include<iostream>

using namespace std;

class sample{
    public:
    static sample* getinstance(const int temp){
        if(instance == nullptr){
            instance = new sample(temp);
        }
        return instance; 
    }
    ~sample(){
        cout << "Destructor called\n";
    }
    int getx();
    private:
    sample(int t1){
        cout << "Constructor called\n";
        x = t1;
    }
    static sample* instance;
    int x;
};

int sample::getx(){
    return x;
}

sample* sample::instance = nullptr;

int main(int argc, char **argv){
    int tmp1;
    if(argc == 2){
        tmp1 = atoi(argv[1]);    
    }
    // sample obj1(tmp1);
    sample *obj = sample::getinstance(6);
    cout << "Object val is : " << obj->getx() << endl;
    sample *obj1 = sample::getinstance(7);
    cout << "Object val is : " << obj1->getx() << endl;
}