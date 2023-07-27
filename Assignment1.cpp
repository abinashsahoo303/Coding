#include<iostream>
#include<thread>
#include<string>

using namespace std;

int i=0;
void num(){
    while(i<100000){
        i++;
    }
}

int main(){
    thread thr1(num);
    thread thr2(num);

    cout << "Total increment value is : " << i << endl;

    thr1.join();
    thr2.join();
}