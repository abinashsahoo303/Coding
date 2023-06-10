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

class test{
   public:
   void hello(){
      std::cout << " Inside Hello fun";
   }
};

 int main(){
    Hello obj;
    std::string str="abc";
    test obj1;
    // std::thread thr(obj);
    // std::thread thr(hello);
    // std::thread thr([](){std::cout << "Hello. Lambda Thread!! \n";});
    
    // Thread with Argument

    // std::thread thr(hello_arg, "Hello,Thread!!");

    //To pass an variable as moved as an entry point for an thread (Rvalue ref)
    // std::thread thr(func,std::move(str));

    // To pass refrence var to an fun as an entry point
    //  std::thread thr(hello_ref,std::ref(str));

    //To pass member function of a class as an entry point to thread
   //  std::thread thr(&test::hello,&obj1);

   // To pass lambda fun as an entry point
   std::thread thr([j = 4](int i){std::cout<< i +j << std::endl;},3);

    thr.join();

    // std::cout << (str.empty() ? "No data available in string" : "Yes data available in string") << "\n";
    //std::cout << str <<std::endl;
    return 0;
 }
