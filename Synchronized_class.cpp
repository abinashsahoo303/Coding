#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>

using namespace std;

class Vector
{
    std::mutex mut;
    std::vector<int> vec;

public:
    void push_back(const int &i)
    {
        mut.lock();
        vec.push_back(i); // critical section
        mut.unlock();
    }

    // void print()
    // {
    //     try
    //     {
    //         mut.lock();
    //         throw std::exception();
    //         for (auto i : vec)
    //         {
    //             cout << i << endl; // critical section
    //         }
    //         mut.unlock();
    //     }
    //     catch(std::exception& e){
    //         cout<< "Exception catched"  << e.what() << endl;
    //     }
    // }
    // To ove come the above unlcoking issue whileexception lock guard is being used
    void print()
    {
        try
        {
            //This call mutex lock
            // std::lock_guard<std::mutex> lck_guard(mut);

            // Unique lock of mutex by usoing unique_lock
            std::unique_lock<std::mutex> uniq(mut);

            for (auto i : vec)
            {
                cout << i << endl; // critical section
            }
            uniq.unlock();
            throw std::exception();
        }
        catch(std::exception& e){
            cout<< "Exception catched"  << e.what() << endl;
        }
    }

};

void func(Vector &vec)
{
    for (int i = 0; i < 5; ++i)
    {
        vec.push_back(i);
        this_thread::sleep_for(50ms);
        vec.print();
    }
}

Vector v1;

int main()
{
    std::thread thr1(func, std::ref(v1));
    std::thread thr2(func, std::ref(v1));
    thr1.join();
    thr2.join();
}