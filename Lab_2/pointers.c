#include <stdio.h>

int main()
{
        int x=0,y=0,*px, *py;
        px = &x;
        py = &y;
        int arr[10];
        printf("The address for x: %p\n", &x);
        printf("The address for y: %p\n", &y);
        printf("The address for px: %p\n", &px);
        printf("The address for py: %p\n", &py);
        printf("The value for px: %d\n", *px);
        printf("The value for py: %d\n", *py);
        for(int i = 0;i<10;i++)
        {
            printf("The contents of arr: %d\n", *(arr+i));
        }
        printf("The address for arr: %p\n", arr);
        printf("The address for arr[0]: %p\n", &arr[0]);
        return 0;
}