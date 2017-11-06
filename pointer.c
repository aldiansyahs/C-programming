/* CS261- Assignment 1 - Q. 0*/
/* Name: Aldiansyah Suryoutomo
 * Date: Oct 2
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

int fooB(int* a, int* b, int c) {
    c=*a+*b;
    *a=*b;
    *b=2*(*b);
    printf("the value of A is %d and the value of B is %d", *a, *b);
    
    return c;
}


void fooA(int* iptr){
    printf("the value of X is %d\n", *iptr);
    printf("the address pointed by iptr is %p\n",iptr);
    printf("the address of iptr is %p\n",&iptr);
    
    
}

int main (){
    int x=10;
    /* declare an integer x */
  		printf("the address of X is %p\n",&x);
    /* print the address of x */
    fooA(&x);
    /* Call fooA() with the address of x */
    printf("the value of X is %d\n",x);
    /* print the value of x */
    
    return 0;
}
