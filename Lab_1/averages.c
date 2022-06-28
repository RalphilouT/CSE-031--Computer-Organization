#include <stdio.h>

int main()
{
    double i,z =1;
    double x=0,x1=0,xavg;
    double y=0,y1=0,yavg;
    int printx, printy;
    while(z !=0)
    {
        printf("Please enter an integer: ");
        scanf("%lf", &i);
        if(i == 0)
        {
            break;
        }
        else if(i > 0)
        {
            x = x + i;
            x1++;
        }
        else if(i < 0)
        {
            y = y + i;
            y1++;
        }
        z = i;
    }
    xavg = x / x1;
    yavg = y / y1;

    if(x == 0 && y != 0)
    {
        printf("\n");
        printf("Negative average: %d \n", (int)yavg);
    }
    else if(y == 0 && x != 0)
    {
        printf("\n");
        printf("Positive average: %d \n", (int)xavg);
    }
    else
    {
        printf("\n");
        printf("Positive average: %d\n", (int)xavg);
        printf("Negative average: %d\n", (int)yavg);
    }
   
}