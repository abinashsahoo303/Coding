#include<stdio.h>
#include<stdbool.h>

bool strincmp(const char* cr1,const char* cr2){
    bool rval = false;
    while(*cr1 & *cr2){
        if(*cr1 == *cr2){
            rval = true;
        }
        cr1++;
        cr2++;
    }
    return rval;
}

int main(){
    printf("Comparison result is : %d\n", strincmp("ABC and","abc and"));
    return 0;
}