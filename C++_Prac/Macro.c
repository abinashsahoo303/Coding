#include"stdio.h"

#define sq(x)(x*x)

void funptr(){
    printf("Inside Fun ptr\n");
}

int main(){
    printf("Square is %d\n",sq(1+2));

    int i=0x01;
    char *ptr;
    ptr= (char *) &i;
    if(*ptr==0)
    printf("big endian\n");
    else
    printf("little endian\n");




    union checkendianess
    {
    int i;
    char c;
    };
    union checkendianess val;
    val.i = 0x0001;
    if(val.c = 0x00)
    printf("big endian\n");
    else
    printf("little endian\n");

    //funptr

    void (*ptrf)(void);
    ptrf = &funptr;
    ptrf();


    return 0;
}