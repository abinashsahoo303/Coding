#include<iostream>
#include<memory>

using namespace std;

class sample{
    public:
    sample() = default;
    sample(int t):x(t){ cout << "constructor called \n";}
    ~sample(){cout << "destructor called \n";}
    sample operator+(sample& other){
        return x+other.x;
    }
    sample operator++(){
        return ++x;
    }

    sample operator++(int){
        sample temp;
        temp.x = x++;
        return temp;
    }

    void print(){
        cout << "val is "<< x << endl; 
    }
    private:
    int x;
};

int main(int argc,char **argv){
    sample obj1(3);
    sample obj2(5);
    sample obj = ++obj2;
    obj.print();
    obj = obj2++;
    obj2.print();
    obj.print();
    
    // obj2.print();
    return 0;
}
