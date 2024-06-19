#include <stdio.h>

int main()
{
    int i, t, a, count, answer = -1;
    scanf("%d", &t);
    scanf("%d", &a);
    int arr[t][t];

    for(i = 0; i < t; i++)
    {
        for(int j = 0; j < t; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(i = 0; i < t; i++)
    {
        count = 0;
        for(int j = 0; j < t; j++)
        {
            if(arr[j][i] == 0) count++;
            if(count == a && answer == -1)
            {
                answer = i;
            } 
            else if(arr[j][i] == 1) count = 0;
        }
    }

    if(answer == -1) printf("N");
    else printf("%d", answer);

    return 0;
}