#include<iostream>


using namespace std;

template<class T>
class sample{
    public:
    sample(T t1){
        cout << "Constructor called\n";
        x = t1;
    }
    ~sample(){
        cout << "Destructor called\n";
    }
    T getx(){
        return x;
    }
    private:
    T x;
};

// template<class T> T sample::getx(){
//     return x;
// }


// template<typename T> void swap(T &a, T &b){
template<typename T>
void swap_f(T& a, T& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(int argc, char **argv){
    int tmp1;
    if(argc == 2){
        tmp1 = atoi(argv[1]);    
    }
    sample<float> obj1(5.2);
    cout << "Object val is : " << obj1.getx() << endl;

    float t1,t2;
    t1 = 300.1;
    t2 = 200.2;
    swap_f<float>(t1,t2);
    cout << "Object val is : " << t1 << "  " << t2 << endl;
}