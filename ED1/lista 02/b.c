#include <stdio.h>
#include <string.h>

char* solve(char str[], int source, size_t size)
{
    if(source >= size/2) return str;

    char save = str[source];
    str[source] = str[size-1-source];
    str[size-1-source] = save;

    return solve(str, source+1, size);
}

int main()
{
    char str[501];
    scanf("%s", str);

    size_t size = strlen(str);
    
    char* newstr = solve(str, 0, size);

    printf("%s", newstr);

    return 0;
}