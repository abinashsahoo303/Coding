#include<iostream>

using namespace std;

class function_object{
    public:
    int operator()(int a, int b){
        return a+b;
    }
};

template <class T>
class fun{
    T x;
    T y;
    public:
    fun(T a,T b)(x=a)(y=b){}
    T operator()(T a,T b){
        return a>b ? a : b;
    }
    
};

int main(int argv,char *argc[]){
    function_object obj;
    cout<< "Return value function object : " << obj(2,3) << endl;

    fun<int> obj; 
    cout << "Template func for return val using fun class object is " << obj(5,6) << endl;

    return 0;
}