#include <stdio.h>
int main()
{
    unsigned int data = 10; //value of data
    data = (data<<1) + data + (data>>1); // equivalent to data * 3.5
    printf("data = %d\n", data);
    return 0;
}
