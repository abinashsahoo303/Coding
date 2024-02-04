#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>

using namespace std;

std::recursive_mutex rmut;

int fact(int n){
    // if(n <= 1){
    //     cout << "fact is : " << 1 << endl;
    //     return 1;
    // }
    int retval;
    //recursive mutex
    std::lock_guard<std::recursive_mutex> lck(rmut);
    // rmut.lock();
    //start critical section
    if(n <= 1){
        retval = 1;
    }
    else{
        retval = n*fact(n-1);
    }
    cout<< "fact is : " << retval << endl;
    //End of critical section
    // rmut.unlock();

    return retval;
}

int main(){
    thread thr1(fact,10);
    thread thr2(fact,13);

    thr1.join();
    thr2.join();
}

