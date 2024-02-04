#include<iostream>
#include<thread>
#include<string>
#include<mutex>

using namespace std;

mutex task_mutex;

int x=0;

void tsk1(int i){
    //Delay
    cout << "Task1 called" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    task_mutex.lock();
    cout << "Task1 locked mutex" << endl;
    x = i;
    //end of critical sec
    task_mutex.unlock();
    cout << "value of X from T1 : " << x << endl;
}

void tsk2(int i){
    //Delay
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "Task2 called" << endl;
    task_mutex.lock();
    cout << "Task1 locked mutex" << endl;
    x = i+1;
    //end of critical sec
    task_mutex.unlock();
    cout << "value of X from T2 : " << x << endl;
}

int main(){
    cout<< "Starting 2 Threads!!\n" << endl;

    std::thread thr1(tsk1,2);
    std::thread thr2(tsk2,3);
    
    thr1.join();
    thr2.join();
}