#include<stdio.h>
long int dec_hex();
int main()
{
int num=1235;
dec_hex(num);
}
long int dec_hex(int num)
{
int rem[10];
int i=0;
int length=0;
while(num>0)
{
rem[i]=num%16;
num=num/16;
i++;
length++;
}
printf("hexadecimal number");
for(i=length-1;i>=0;i--)
{
switch(rem[i])
{
case 10:printf("a");
break;
case 11:printf("b");
break;
case 12:printf("c");
break;
case 13:printf("d");
break;
case 14:printf("e");
break;
case 15:printf("f");
break;
default:printf("%d",rem[i]);
}
}
}
