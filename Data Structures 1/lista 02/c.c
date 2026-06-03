#include <stdio.h>
#include <string.h>

int solve(char str[], int depth)
{
    long int sum = 0;
    int size = strlen(str);
    for(int i = 0; i < size; i++)
    {
        sum += (str[i] - '0');
    }

    if(!(sum/10))
    {
        if(sum%9) return 0;
        else return depth;
    }

    char newstr[1001];
    sprintf(newstr, "%d", sum);

    return solve(newstr, depth+1);
}

int main()
{
    char str[1001];
    while(scanf("%s", str), str[0] - '0' != 0)
    {
        int num = solve(str, 1);

        if(num) printf("%s is a multiple of 9 and has 9-degree %d.\n", str, num);
        else printf("%s is not a multiple of 9.\n", str);
    }

    return 0;
}