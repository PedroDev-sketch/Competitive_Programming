#include <stdio.h>

int main()
{
    char str[1000], rev[1000];
    int count = 0;
    scanf("%s", str);
    while(str[count] != 0)
    {
        count++;
    }
    int j = count - 1;
    for(int i = 0; i < count; i++)
    {
        rev[i] = str[j];
        j--;
    }
    printf("%s", rev);
    return 0;
}