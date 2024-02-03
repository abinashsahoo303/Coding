#include<iostream>
#include<memory>

using namespace std;

class sample{
    public:
    sample(int t1){
        cout << "Constructor called\n";
        // std::unique_ptr<int> x(new int);
        x = new int;
        *x = t1;
    }

    ~sample(){
        if(x != nullptr){
            cout << "Destructor called for x with address  " << x << endl;
        }
        else{
            cout << "Destructor called\n";
        }
        delete x;
    }

    sample(sample const& other){
        cout << "Copy constructor called \n";
        x = new int;
        x = other.x;
    }

    // sample(sample&& other){
    //     cout << "Move constructor called \n";
    //     x = other.x;
    //     other.x = nullptr;
    // }

    sample& operator =(sample&& other){
        cout << "Move assignment operator called \n";
        x = other.x;
        other.x = nullptr;
        return *this;
    }

    // sample& operator =(sample const& other){
    //     cout << "Copy assignment operator called \n";
    //     x = other.x;
    //     return *this;
    // }

    // sample(sample const& other) = delete;

    int getx();
    private:
    int *x;
    sample& operator =(sample const& other);
    // sample(sample const& other);
    sample(sample&& other);
    // sample& operator =(sample&& other);
};

int sample::getx(){
    return *x;
}

int main(int argc, char **argv){
    int tmp1;
    if(argc == 2){
        tmp1 = atoi(argv[1]);    
    }
    sample obj1(tmp1);
    // cout << "Object val is : " << obj1.getx() << endl;

    // sample obj2(obj1); // Copy constructor
    sample obj2 = obj1; // Copy constructor
    // sample obj2(4);
    // obj2 = obj1; // Copy assignment operator

    // cout << "Old Object val is : " << obj1.getx() << endl; 
    // cout << "New Object val is : " << obj2.getx() << endl; 

    // sample obj3(std::move(obj1)); //Move Construtor
    // sample obj3 = std::move(obj1); //Move Construtor
    sample obj3(4);
    obj3 = std::move(obj1);  //Move assignment

    // cout << "Old Object val is : " << obj1.getx() << endl; 
    // cout << "New Object val is : " << obj3.getx() << endl; 

}