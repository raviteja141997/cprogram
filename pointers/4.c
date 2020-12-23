#include <stdio.h>

int main()
{

    int c = 1;
    int d = 2;
    int e = 3;
    int * a = &c;
    int * b = &d;
    int * f = &e;
    int ** pp = &a;  // pointer to pointer 'a'

    printf("\n a's value: %x \n", a);
    printf("\n b's value: %x \n", b);
    printf("\n f's value: %x \n", f);
    printf("\n can we change a?, lets see \n");
    printf("\n a = b \n");
    a = b;
    printf("\n %x, same as 'b' \n", a);
  //  printf("\n cant_change(a, f); \n");
    cant_change(a, f);
    printf("\n a's value is now: %x \n", a);

   // printf("\n NOW! lets see if a pointer to a pointer solution can help us... remember that 'pp' point to 'a' \n");
     printf("\n change(pp, f); \n");
    change(pp, f);
    printf("\n a's value is now: %x\n", a);
    return 0;
}

void cant_change(int * x, int * z){
    x = z;
    printf("\n ----> value of 'a' is: %x \n", x);
}

void change(int ** x, int * z){
    *x = z;
    printf("\n ----> value of 'a' is: %x \n", *x);
}
