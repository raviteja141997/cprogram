#include<stdio.h>
int main()
{
volatile int a=10;
volatile int b=10;
volatile int c=a*b;
printf("%d",c);
}
