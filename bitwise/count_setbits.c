#include<stdio.h>

int main()
{
int n=8;
int c_set=0;
int n_inv=0;
int c_clear=0;
while(n)
{

c_set+=n&1;

n>>=1;
n_inv=~n;
c_clear+=n_inv&1;
n_inv>>=1;
//n&=n-1;
//c++;
}
printf("set bits%d\nclear bits%d\n",c_set,c_clear);
}
