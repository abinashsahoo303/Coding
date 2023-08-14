#include<iostream>
#include<csignal>

using namespace std;

sig_atomic_t signal_val;

void signal_h(int sig){
    signal_val = sig;
}

int main(){
    signal(SIGUSR2,signal_h);
    cout << "Value of Signals before raise : " << signal_val << endl;
    raise(SIGUSR2);
    cout << "Value of Signals after raise : " << signal_val << endl;
}