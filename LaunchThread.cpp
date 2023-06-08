#include<iostream>
#include<thread>
#include<string>

 void hello(){
    std::cout<< "Hello Thread!!\n";
 }
 class Hello{
    public:
        void operator()(){std::cout<< "hello, Function Thread!!! \n";} 
 };

 void hello_arg(std::string st){
    std::cout << st << std::endl;
 }


//Pass by move for rvalue
void func(std::string && str){
    std::cout << "Ownership of " << str << "transferred to thread "<< std::endl; 
}         

//Obj Pass by reference
void hello_ref(std::string& str){
    str = "xyz";
}

 int main(){
    Hello obj;
    std::string str="abc";

    // std::thread thr(obj);
    // std::thread thr(hello);
    // std::thread thr([](){std::cout << "Hello. Lambda Thread!! \n";});
    
    // Thread with Argument

    // std::thread thr(hello_arg, "Hello,Thread!!");
    // std::thread thr(func,std::move(str));
    std::thread thr(hello_ref,std::ref(str));
    

    thr.join();

    // std::cout << (str.empty() ? "No data available in string" : "Yes data available in string") << "\n";
    std::cout << str <<std::endl;
    return 0;
 }
