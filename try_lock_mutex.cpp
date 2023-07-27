#include<iostream>
#include<thread>
#include<string>
#include<mutex>
#include<vector>

using namespace std;

std::mutex task_mutex;

void task2(){
    // cout is a global data  which is being used between multiple task
        cout << "Task2 trying to lock mutex" << endl;
        while(!task_mutex.try_lock()){
        //start of criical sec
        cout << "Task2 unable to lock mutex" << endl;
        this_thread::sleep_for(1s);
        }
        cout << "Task2 locked mutex" << endl;
        //end of critical sec
        task_mutex.unlock();
        cout << "Task2 unlocked mutex" << endl;
    }


void task1(){
    // cout is a global data  which is being used between multiple task
        cout << "Task1 trying to lock mutex" << endl;
        task_mutex.lock();
        cout << "Task1 locked mutex" << endl;
        this_thread::sleep_for(5s);
        //end of critical sec
        task_mutex.unlock();
        cout << "Task1 unlocked mutex" << endl;
    }

// class thread_guard{
//     std::thread thr;
//     public:
//     // consturctor with rvalue reference
//     explicit thread_guard(std::thread&& thr):thr(std::move(thr)){}
//     ~thread_guard(){
//         if(thr.joinable()){
//             thr.join();
//         }
//     }
//     thread_guard(const thread_guard&) = delete; //deleted copy operators
//     thread_guard& operator =(const thread_guard&) = delete;
// };

int main(){
    cout<< "Starting 3 Thread!!\n" << endl;

    std::thread thr1(task1);
    std::thread thr2(task2);

    
    thr1.join();
    thr2.join();


}