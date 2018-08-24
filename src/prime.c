#include <stdio.h>

unsigned int checkIsPrime(unsigned int test)
{
    unsigned int i,rem,isPrime;
    isPrime = 1;
    for(i=2;i < test ;i++)
    {
        rem = test % i;
        // printf("%d / %d is %d : %d \n", integer, i, divi, rem);
        if(rem == 0U)
        {
            isPrime = 0;
        }
    }
    // if(isPrime)
    // {
    //     printf("%d is a prime number \n", test);
    // }else
    // {
    //     printf("%d is not a prime number \n", test);
    // }
    return(isPrime);
}

int main(void)
{
    unsigned int integer = 0,i,j;
    printf("Program name: %s\n", __BASE_FILE__);
    printf("Enter a non zero positive number: ");
    scanf("%d", &integer);
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

    return 0;
}