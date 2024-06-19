#include <stdio.h>

int main()
{
    float total = 0, count = 0;
    char n, text[1001], ant = ' ';
    int flag = 0;
    scanf("%c", &n);
    scanf(" %1000[^\n]", text);
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == n) flag = 1;
        if(text[i] == ' ' && ant != ' ') 
        {
            count++;
            if(flag) total++;
            flag = 0;
        }
        ant = text[i];
    }
    if(ant != ' ')
    {
        count++;
        if(flag) total++;
    }
    printf("%.1f\n", (total/count) * 100);
    return 0;
}