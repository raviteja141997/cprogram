#include<stdio.h>
int main()
{
int a=0;
int sign=0;
printf("enter data");
scanf("%d",&a);
sign=(a>0)-(a<0);
if(sign==1)
printf("positive number");
if(sign==-1)
printf("negative number");
if(sign==0)
printf("0 number");


}
