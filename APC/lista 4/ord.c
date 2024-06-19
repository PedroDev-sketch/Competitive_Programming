#include <stdio.h>

int main()
{
    int p, flag;
    char word[43];
    scanf("%d", &p);
    for(int i = 0; i < p; i++)
    {
        flag = 0;
        scanf("%s", word);
        for(int j = 1; word[j] != '\0'; j++)
        {
            char prev = word[j - 1] >= 'a' ? word[j - 1] - 32 : word[j - 1]; 
            char curr = word[j] >= 'a' ? word[j] - 32 : word[j];
            if(curr <= prev)
            {
                flag = 1;
                break;
            }
        }
        if(!flag) printf("%s: O\n", word);
        else printf("%s: N\n", word);
    }
    return 0;
}