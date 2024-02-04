#include <iostream>
#include <thread>
#include <string>
// #include <mutex>
#include <vector>
#include <shared_mutex>

using namespace std;

// std::mutex task_mutex;
// Shared MMutex to lock the shared resource
std::shared_mutex task_mutex;
int x = 0;

class A
{
public:
    void write()
    {
        std::lock_guard<std::shared_mutex> lck_grd(task_mutex);
        // Start critical sec
        cout << "Write locked mutex" << endl;
        ++x;
        cout << "Write unlocked mutex" << endl;
        //
    }

    void read()
    {
        std::shared_lock<std::shared_mutex> lck_grd(task_mutex);
        // Start critical sec
        using namespace std::literals;
        cout << "Read locked mutex" << endl;
        std::this_thread::sleep_for(1000ms);
        cout << x << endl;
        cout << "Read unlocked mutex" << endl;
        // end
    }
};

void write()
{
    std::lock_guard<std::shared_mutex> lck_grd(task_mutex);
    // Start critical sec
    cout << "Task1 locked mutex" << endl;
    ++x;
    cout << "Task1 unlocked mutex" << endl;
    // end critical section
}

void read()
{
    std::shared_lock<std::shared_mutex> lck_grd(task_mutex);
    // Start critical sec
    using namespace std::literals;
    cout << "Task2 locked mutex" << endl;
    std::this_thread::sleep_for(1000ms);
    cout << x << endl;
    cout << "Task2 unlocked mutex" << endl;
    // end critical section
}

// void task2(){
//     // cout is a global data  which is being used between multiple task
//         cout << "Task2 trying to lock mutex" << endl;
//         while(!task_mutex.try_lock()){
//         //start of criical sec
//         cout << "Task2 unable to lock mutex" << endl;
//         this_thread::sleep_for(1s);
//         }
//         cout << "Task2 locked mutex" << endl;
//         //end of critical sec
//         task_mutex.unlock();
//         cout << "Task2 unlocked mutex" << endl;
//     }

// void task1(){
//     // cout is a global data  which is being used between multiple task
//         cout << "Task1 trying to lock mutex" << endl;
//         task_mutex.lock();
//         cout << "Task1 locked mutex" << endl;
//         this_thread::sleep_for(5s);
//         //end of critical sec
//         task_mutex.unlock();
//         cout << "Task1 unlocked mutex" << endl;
//     }

int main()
{
    cout << "Starting Thread!!\n"
         << endl;

    A * obj1 = new A();
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(std::thread(&A::read,obj1));
    }

    threads.push_back(std::thread(&A::write,obj1));
    threads.push_back(std::thread(&A::write,obj1));

    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(std::thread(&A::read,obj1));
    }

    for (auto &thr : threads)
        thr.join();

    delete obj1;
}