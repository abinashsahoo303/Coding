#include<iostream>
#include<sstream>

using namespace std;


int main(int argc,char *argv[]){
    int val;
    cout<< "Enter interger";
    cin>>val;

    stringstream s;
    s<<val;
    string v;
    s>>v;
    cout << "converted interger :  " << val << "  into string val is : " << v <<endl;
}