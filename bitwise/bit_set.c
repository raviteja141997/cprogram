#include<stdio.h>
int main()
{
unsigned int my_number;

unsigned int set_number;
printf("enter my number\n");
scanf("%d",&my_number);
int dup=my_number;
printf("enter set number\n");
scanf("%d",&set_number);
my_number &=~(1<<set_number);
if (my_number==dup)
printf(" bit is clear %d",my_number);
}
