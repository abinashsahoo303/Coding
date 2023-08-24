#include <stdio.h> /* function declaration */
extern int i;
void next(void);
static int counter = 7; /* global variable */
int main() {
 while(counter<10) {
      next();
      counter++;   }
 printf("Extern value if i : %d\n",i);
return 0;}
void next( void ) {    /* function definition */
   static int iteration = 13; /* local static variable */
   iteration ++;
   printf("iteration=%d and counter= %d\n", iteration, counter);}
