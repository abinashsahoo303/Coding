#include<stdio.h>
#include<stdlib.h>

// #define Hello



int val = 9999;
const int *pval = &val;  // defines pointer to a const: 
                        // Pointer Value cannot be change

int *const pnewval = &val;  // pointer address cannot be changed
int temp = 666;

int* test(const int *ptr){
    int *val = (int *)malloc(sizeof(int));
    *val = *ptr;
    *val = *val + 1;
    free(val);
    return val;
}


int main(){
    // *pval = 888; Not possible
    val = 777; // Possible
    printf("Val is = %d\n",*pval);

    // pnewval = &temp; Not possible
    val = 555;
    *pnewval = 666; // Possible
    printf("Val is = %d\n",val);

    printf("value after test fun call : %d\n",*(int *)(test(&val)));

    #ifdef Hello
    printf("Val of Macro is: %d\n",Hello);
    #else
    printf("Val of Macro is: %s\n",__DATE__);
    #endif
    return 0;
}