#include <stdio.h>
int decimal(double value)
{
    int truncated = (int)value;
    return (value == truncated);
}
int main()
{
    double numREP;
    double locREP;
    printf("Enter the number of repetitions for the punishment phrase: ");
    scanf("%lf", &numREP);
    if(numREP < 0 || decimal(numREP) == 0)
    {
        printf("\n");
        printf("You entered an invalid value for the number of repetitions! Must be positive integers!");
        return 0;
    }
    else
    {
        printf("Enter the repetition count when you wish to introduce a typo: ");
        scanf("%lf", &locREP);
        printf("\n");
        if(locREP < 0 || decimal(locREP) == 0)
        {
            printf("You entered an invalid value for the type placement! Must be positive integers!");
            return 0;
        }
        for(int i = 1; i < locREP; i++)
        {
            printf("C programming language is the best! ");
        }
        printf("C programmming lnguage is the bet! ");
        for(int i = locREP; i < numREP; i++)
        {
            printf("C programming language is the best! ");
        }

    }
    

    return 0;
}