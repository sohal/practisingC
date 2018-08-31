#include "palindrome.h"

uint32_t stringSize(char* src)
{
    char* ptr = src;
    while(*ptr++);
    return(ptr-src);
}

uint32_t strCompare(char *start, char *end)
{
    if(*start == *end)
    {
        if((start == end) || ((start + 1U) == end))
        {
            return( 1U );
        }
        return(strCompare(start + 1, end - 1));
    }else
    {
        return( 0U );
    }
}

int main(int argc, char *argv[])
{
    uint32_t strSize;

    printf("Program name: %s\n", __BASE_FILE__);
    if(2 == argc)
    {
        strSize = stringSize(argv[1]);
        printf("The string is %s a palindrome\n",(strCompare(argv[1], argv[1] + strSize - 2U) != 0) ? "\b" : "not");
    }else
    {
        printf("Usage ...\n");
    }
    return 0;
}
