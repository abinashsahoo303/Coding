#include<iostream>
#include<thread>
#include<string>

using namespace std;

//Display thread id
void hello(){
    // std::this_thread::sleep_for(5s);
    cout << "Hello Thread after 5 Sec \n" ; 
    // cout<< "Thread has id " << std::this_thread::get_id() <<endl;
}

void excep(){
    try{
        throw std::exception();
    }
    catch (std::exception& e){
        std::cout << "Exception caught" << e.what() << endl;
    }
    cout << "hello thread" << endl;
}

//Function taking thread as a n argument
void func(std::thread thr){
    cout<< "Recieve thread with id  " <<thr.get_id() <<"\n" ;
    thr.join();
}

//Function return thread as return
std::thread rth(){
    // std::thread thr(hello);
    //return a local var
    // return thr;

    //return a temp object
    return std::thread(hello);
}
int main(){
    // cout << " Main Thread id  " << std::this_thread::get_id() << endl;
    cout << "Starting thread... \n";
    // std::thread thr1(hello);

    // std::thread thr2([](){cout<< "hello thr2 " << endl;});


    //Display thread's native handle
    // cout<< "Thread1 has its native handle " << thr1.native_handle() << endl;

    //Display Thread id
    // cout<< "Hello Thread Id " << thr1.get_id() << endl;

    // Pass a named object using std::move
    // func(std::move(thr1));

    //Pass a temporary object
    // func(std::thread(hello));

    // thr1.join();
    //Display child thread native id
    // cout<< "Thread1 has after thread native handle " << thr1.native_handle() << endl;


    //Display child thread id
    // cout<< "Hello Thread after completion has Id " << thr1.get_id() << endl;
    // thr2.join();

    // std::thread thret=rth();
    // cout << "thread id of ret thread  " <<thret.get_id() << endl;

    // thret.join();

    std::thread thr(excep);
    thr.join();

}