#include <iostream>
#include <thread>
#include <string>

using namespace std;

int x, y, z;

int main()
{
    thread thr1([]()
                { x = x + 3; });
    thread thr2([]()
                { y = x + 2; });
    thread thr3([]()
                { z = x + 3; });

    thr1.join();
    thr2.join();
    thr3.join();

    cout << " Value of X : " << x << endl;
    cout << " Value of Y : " << y << endl;
    cout << " Value of Z : " << z << endl;
}