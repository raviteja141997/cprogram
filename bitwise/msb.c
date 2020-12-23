#include <stdio.h>
int main()
{
    unsigned int mask = 0; // mask flag
    unsigned int i = 30; // ith position till u want to clear the bits
    unsigned int data = 15; //value of data
    mask = (1 << (i+1)); //Shift 1 ith position
    mask = mask -1 ; //give us 00000111
    //Now clear all bits from msb to ith position
    data  = data & mask;

    printf("data = %d\n", data);
    return 0;
}
