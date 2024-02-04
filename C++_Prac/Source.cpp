#include<iostream>
#include<vector>

using namespace std;

// Namespace alias 
// namespace sc = std::chrono;

void func(int&& i){
    cout << "func(int) called\n" ;
}

// void func(int *i){
    // cout << "func(int) called\n" ;
// }
std::vector<int> vec{4,2,3,6,1};
auto x = [](int arg){return 2*arg;};
int y=3;




int main(){
    // func(NULL);
    // func(nullptr);
    // sc::seconds(2);   // 2 second interval
    cout<< x(2) << endl;

    for(auto i:vec){
        cout << "Vector val is " << i << endl; 
    }

    // auto n_even = std::__count_if(vec.begin(),vec.end(),[](int n){return (n%2 == 0);});

    // cout << "The vector has " << n_even << "elements with even values \n";

    func(std::move(y));

}