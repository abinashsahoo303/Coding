#include<iostream>
#include<thread>
#include<string>
#include<mutex>

using namespace std;

std::mutex task_mutex;

void task(std::string str){
    // cout is a global data  which is being used between multiple task
    for(int i=0;i < 5; ++i){
        task_mutex.lock();
        //start of criical sec
        cout << str[0] << str[1] << str[2] << endl;
        //end of critical sec
        task_mutex.unlock();
    }
}


class thread_guard{
    std::thread thr;
    public:
    // consturctor with rvalue reference
    explicit thread_guard(std::thread&& thr):thr(std::move(thr)){}
    ~thread_guard(){
        if(thr.joinable()){
            thr.join();
        }
    }
    thread_guard(const thread_guard&) = delete; //deleted copy operators
    thread_guard& operator =(const thread_guard&) = delete;

};

int main(){
    cout<< "Starting 3 Thread!!\n" << endl;

    std::thread thr1(task,"abc");
    std::thread thr2(task,"def");
    std::thread thr3(task,"xyz");
    
    thr1.join();
    thr2.join();
    thr3.join();

}