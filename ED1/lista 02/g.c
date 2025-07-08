#include <stdio.h>
#include <string.h>

void solve(char str[], int source, int size)
{
    if(source == size)
    {
        return;
    }

    if(str[source] == 'x') str[source] = 'y';

    return solve(str, source+1, size);
}

int main()
{
    char str[81];
    scanf("%s", str);
    int size = strlen(str);
    solve(str, 0, size);

    printf("%s\n", str);

    return 0;
}