#include<stdio.h>
//#pragma pack(1)
struct test
{
double d;
float b[5];
//char a[];
int c[10];
char e[10];
//double d;
}test;
int main()
{
printf("%d",sizeof(test));
printf("address of b %u\n",&test.b);
//printf("address of a %u\n",&test.a);
printf("address of c %u\n",&test.c);
printf("address of d %u\n",&test.d);
}
