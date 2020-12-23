#include <stdio.h>
 
int main()
{
    unsigned short int data=0x1234;
    printf("\ndata before swapping : %04X",data);
 
 //int a=((data>>4)&0x0f);
//int b=((data<<4)&0xf000);
//a=a|b;
data=((data>>4)&0x0f0f)|((data<<4)&0xf0f0);



    printf("\ndata after swapping  : %04X",data);
 
    return 0;
}



