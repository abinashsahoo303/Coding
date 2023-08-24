#include<stdio.h>
#include<string.h>

char* retop(const char* str){
    printf("Original string is %s\n",str);
    char* temp = NULL;
    int val = strlen(str);
    int tem = val;
    printf("%s\n",*str[0]);
    // for(int i=0; i <= val; i++){
    //     temp[tem] = str[i]; 
    //     tem--;
    // }
    return temp;
}

int main(int argv,char *argc[]){
    if(argv < 2){
        return 0;
    }
    printf("Reverese string is %s\n",retop(argc[1]));
    return 0;
}