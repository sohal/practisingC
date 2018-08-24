#include <stdio.h>

int main(void)
{
    unsigned int rows = 0;
    unsigned int i,j;
    printf("Program name: %s\n", __BASE_FILE__);
    printf("Enter Lines required (non zero positive number): ");
    scanf("%d", &rows);
    putchar('\n');
    for(i=0; i<rows; i++)
    {
        for(j=rows-i; j; --j)
        {
            putchar('*');
        }
        for(j=i; j; --j)
        {
            putchar(i+'0');
        }
        if(i>0)
        for(j=i-1; j; --j)
        {
            putchar(i+'0');
        }
        if(i==0)
        {
            for(j=rows-1; j; --j)
            {
                putchar('*');
            }
        }
        else
        {
            for(j=rows-i; j; --j)
            {
                putchar('*');
            }
        }
    
        putchar('\n');
    }
    return 0;
}