#include<stdio.h>

extern int *b; /* only declaration, b is defined in other file.*/

int main()
{


        printf("%d\n",*b); /* dereferencing b will give the value of variable a in file a.c */
        return 0;
}
