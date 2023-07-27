#include<iostream>
#include<thread>
#include<string>

using namespace std;

void hello(int num){
    //Delay
    std::this_thread::sleep_for(std::chrono::seconds(num));
    cout<< "hello from Thread: " << num << endl;
}

void print(std::string str){
    // cout is a global data  which is being used between multiple task
    for(int i=0;i < 5; ++i){
        cout << str[0] << str[1] << str[2] << endl;
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

    // std::thread thr1(hello,1);
    // std::thread thr2(hello,2);
    // std::thread thr3(hello,3);

    // thread_guard thg1(std::move(thr1));
    // thread_guard thg2(std::move(thr2));
    // thread_guard thg3(std::move(thr3));

    std::thread thr1(print,"abc");
    std::thread thr2(print,"def");
    std::thread thr3(print,"xyz");
    
    thr1.join();
    thr2.join();
    thr3.join();

}