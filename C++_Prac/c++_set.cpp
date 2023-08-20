#include<iostream>
#include<set>
using namespace std;

int main(){
    std::set<int,greater<int>> obj;

    obj.insert(5);
    obj.insert(9);
    obj.insert(12);

    for(auto &i: obj){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}