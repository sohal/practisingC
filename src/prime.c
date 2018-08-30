#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
unsigned int checkIsPrime(unsigned int test)
{
    unsigned int i,rem,isPrime;
    isPrime = 1;
    for(i=2;i < test ;i++)
    {
        rem = test % i;
        if(rem == 0U)
        {
            isPrime = 0;
        }
    }
    return(isPrime);
}

int main(int argc, char *argv[])
{
    unsigned int integer = 0,i;
    char *eptr= NULL;
    unsigned long long convResult = 0U;
    printf("Program name: %s\n", __BASE_FILE__);
    if(argc > 1)
    {
        convResult = strtoll(argv[1], (char ** __restrict__ )eptr, 10);
        if(convResult == 0U)
        {
            exit(0);
        }
        integer = convResult;
        if(integer < 2)
        {
            printf("The number is %d", integer);
            return 0;   
        }
        for(i=2; i <= integer; i++)
        {
            if(checkIsPrime(i))
            {
                printf(":%d:",i);
            }
        }
        putchar('\n');
    }else
    {
        printf("Usage...\n");
    }
    return 0;
}