#include <stdio.h>
#define INT_BITS 32
#define ROTATE_LEFT(pos, data) ((data << pos))//|(data >> (30)))
#define ROTATE_RIGHT(pos, data) ((data >> pos))//|(data << (30)))
int main()
{
    int pos = 2; // Number of rotation
    int data = 16; //data which will be rotate
    printf("%d Rotate Left by %d is ", data, pos);
    printf("%d \n", ROTATE_LEFT(pos, data));
    printf("%d Rotate Right by %d is ",data, pos);
    printf("%d \n", ROTATE_RIGHT(pos, data));
    return 0;
}
