#include <stdio.h>

int contain(char s[1001][81], char p[1001][81])
{
    int num = 0;
    for(int i = 0; p[i][0] != '\0'; i++)
    {
        for(int j = 0; s[j][0] != '\0'; j++)
        {
            int k = 0;
            while(p[i][k] != '\0' && s[j][k] != '\0' && p[i][k] == s[j][k])
            {
                k++;
            }
            if (p[i][k] == '\0' && s[j][k] == '\0')
            {
                num = 1;
                break;
            } 
        }
    }

    return num;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char s[1001][81], p[1001][81];
    for(int i = 0; i < n; i++)
    {
        scanf(" %s", s[i]);
    }

    for(int i = 0; i < m; i++)
    {
        scanf(" %s", p[i]);
    }

    printf("%d\n", contain(s, p));
    return 0;
}