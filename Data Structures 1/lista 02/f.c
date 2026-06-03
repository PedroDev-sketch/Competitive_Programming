#include <stdio.h>
#include <string.h>

int solve(char str[], int source, int sum, int size)
{
    if(source == size)
    {
        return sum;
    }

    return solve(str, source+1, sum+(str[source]-'0'), size);
}

int main()
{
    char str[31];
    scanf("%s", str);
    int size = strlen(str);
    int num = solve(str, 0, 0, size);

    printf("%d\n", num);

    return 0;
}