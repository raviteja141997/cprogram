#include<stdio.h>
int main()
{
    int num,i,fact = 1;
    printf("Enter a positive number\n");
    scanf("%d",&num);
 
    for(i = 1; i <= num; i++){
        fact = fact * i;
        printf("%d: %d: %d\n",num,fact,i);
    }
   return 0;
}

