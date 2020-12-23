#include<stdio.h>
#include<stdlib.h>
int main()
{
int *p=NULL;
int i=0;
p=(int*)malloc(4*sizeof(int));
for(i=0;i<4;i++)
{
printf("%d",*(p+i));
}
}
