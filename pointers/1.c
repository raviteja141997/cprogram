#include<stdio.h>

int main()
{
    char *str = "Hello";
    char *const p=str;
    *p='M';
    printf("%s\n", str);
    return 0;
}

