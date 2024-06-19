#include <stdio.h>

int main()
{
    int n, comp = -1, answer = 0;
    scanf("%d", &n);
    int grade[n], plan[101] = {0};

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &grade[i]);
        plan[grade[i]]++;
    }

    for(int i = 0; i < 101; i++)
    {
        if(comp < plan[i])
        {
            comp = plan[i];
            answer = i;
        }
        else if(comp == plan[i] && i > answer)
        {
            answer = i;
        }
    }

    printf("%d\n", answer);
    return 0;
}