#include<iostream>
// #include"D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\Calculator\my_add_lib\add.cpp"
// #include"D:\Repo_GIT\Coding\L1_31st_Jan_24\Makelistss_project\Calculator\my_mul_lib\mul.cpp"
#include"add.h"
#include"mul.h"

using namespace std;

int main(int argc,char **argv){
    cout << "Calculator started with no of arguments : " << argc << "\n";
    if(argc == 4){
        switch (atoi(argv[1]))
        {
        case 1:
            cout << "Addition called\n";    
            add(atoi(argv[2]),atoi(argv[3]));
            break;
        case 2:
            cout << "Multiplication called\n";  
            mul(atoi(argv[2]),atoi(argv[3]));
            break;

        default:
            cout << "Invalid cond\n";
            break;
        }
    }
    else{
        cout << "Arguments are not valid\n"; 
    }
}