#include <stdio.h>

int main(void)
{
    unsigned int rows = 0;
    unsigned int i,j,k;
    printf("Enter Lines required: ");
    scanf("%d", &rows);
    putchar('\n');
    for(i=1; i<rows+1; i++)
    {
        for(j=rows-i; j; --j)
        {
            putchar(' ');
        }
        for(j=i; j; --j)
        {
            putchar('*');
        }
        for(k=i; k>1; --k)
        {
            putchar('*');
        }
    
        putchar('\n');
    }
    getchar();
    return 0;
}