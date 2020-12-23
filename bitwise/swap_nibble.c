#include <stdio.h>
//Macro to swap nibbles
#define SWAP_NIBBLES(data) ((data & 0x0F)<<4 | (data & 0xF0)>>4)
int main()
{
    unsigned char value = 100; //value in hex
  
unsigned char left=(value&0x0F)<<4;
printf("%u",left);
unsigned char right=(value&0xF0)>>4;
printf("%u",right);

    printf("%u", SWAP_NIBBLES(value)); //print after swapping
  
    return 0;
}
