#include<utility>

class test{
    public:
    //to block copy and move constructor
    // In C++ 11 we need to declare the same in private member function
    test(const test&) =delete;
    test& operator =(const test&) =delete;


    //For default
    test(test&&) noexcept =default;
    test& operator=(test&&) noexcept =default;
    test()=default;
};

int main(){
    test t1;
    // test t3=t1;
    test t2(std::move(t1));

    return 0;
}