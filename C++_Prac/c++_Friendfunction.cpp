#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std;

template <class T>
class ftest
{
    friend T retadd(ftest &obj)
    {
        return obj.a + obj.b;
    }
    friend void printtest(ftest &obj)
    {
        cout << " Objects values are : " << obj.a << " : " << obj.b << endl;
    }

private:
    T a;
    T b;

public:
    ftest(T x, T y)
    {
        a = x;
        b = y;
    }
};

class Friendclass
{
    int a;
    friend void printval(Friendclass &obj)
    {
        cout << " Friendclass obj are : " << obj.a << endl;
    }

public:
    Friendclass(int x)
    {
        a = x;
    }
};

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        cout << "No argument to handle" << endl;
    }
    else
    {
        if (argc == 3)
        {
            ftest<int> tobj(atoi(argv[1]), atoi(argv[2]));
            cout << "Object created with two arguments" << endl;
            printtest(tobj);
        }
        else
        {
            cout << " More than two argument " << endl;
        }
    }

    ftest<float> tobj1(atof(argv[3]),atof(argv[4]));
    cout << "3rnd and 4th Arguments are : " << argv[3] << "\t" << argv[4] << endl;
    cout << "Addition of the objects are : " << retadd(tobj1) << endl;

    return 0;

}
