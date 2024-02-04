#include<iostream>
using namespace std;
template<typename T>
T add(T val1,T val2)
{
    return val1 + val2;
}

template<class T>
class number{
private:
    T val;
public:
    T getnum()
    {
        return val;
    }
    number(T valm)
    {
        val = valm;
    }
};

int main()
{
    int res;
    res = add<int>(5,4);
    cout<< "Result is  " << res << endl;
    number<int> numobj(3);
    cout<< "Return val is  "<< numobj.getnum() << endl;
}