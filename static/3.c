#include<stdio.h>
int fun();
int main()
{
int a=fun();
printf("%d",a);
}
int fun()
{
static int a=10;
printf("%d",a);
a++;
return 1,2,3,4;
}
