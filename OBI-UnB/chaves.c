#include <stdio.h>

int main()
{
    int n, count = 0;
    scanf(" %d", &n);
    getchar();

    char line[101];

    for(int i = 0; i < n; i++)
    {
        fgets(line, 101, stdin);
        for(int j = 0; j < 101 && line[j] != '\0'; j++)
        {
            if(line[j] == '{') count++;
            else if(line[j] == '}') count--;
            if(count < 0) break;
        }
        if(count < 0) break;
    }

    if(count == 0) printf("S");
    else printf("N");
    return 0;
}