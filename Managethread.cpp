#include<iostream>
#include<thread>
#include<string>

using namespace std;

void hello(){
    cout<< "hello Thread!!\n";
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
    try{
        std::thread thr(hello);
        thread_guard tguard{std::move(thr)};
        throw std::exception();

        // No expection if we got here - call Join() -- Usua; case
        // thr.join();
    }
    catch(std::exception& e){
        std::cout << "Exception caught: " <<e.what() <<  endl;
        // thr.join(); // Call join() before thr desc is called
    }
}