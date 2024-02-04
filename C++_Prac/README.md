# Project for MultiThreading



1. Lambda function expression
2. Rvalue Refernces and Overloading
    void func(const int& t);  //called whne we pass an lvalue
    void fund(int&& t);  // called when we pass an rvalue

    Usually, the lvalue version will be called
        When we pass a variable
    The rvalue overload will be called
        if we pass a literal or a temporary object
        if we use std::move() to cast a variable

3. Move-only Types
    std::fstream : Constructor open and destructor close the file
                    Object cant be copied
    std::iostream 
    std::unique_ptr
    These follow the RAII idiom

4. To prevent an object from being copied : Test(const test& other)=delete;  

5. Default copy constructor : Test(const Test& other)=default;

6. COncurrency:
    Perform two activities at the same time. 

7. Thread fun with Pass by Value and Move
    lvalue as arg : Pass by Value
    Rvalue as arg : Pass by Move

    Pass by Move:
        //Callable obj- thread entry point
            void func(std::string &&);
            std::string str="abc";
            std::thread thr(func,std::move(str));

    Pass by Value:

8. Thread object only movable not copiable.

9.  thr.Join()      --> Parent thread stops and allow child thread to run
    thr.detach()    --> Parent thread runs along with the child thread

    The destructor are called for every object in scope::
        while running a thread , it checks whther join() or detach() have been called. If neither, it calls std::terminate()
    We must call either join() or detach() before the thread is destroyed.

10. Lock_guard is being used for unlocking the mutex by making out of scope of mutex object.

11. unique_lock can be use for unlocking the mutex while exception or if any thread is unable to unlock the mutex.
    unique lock is slower than lock guard
