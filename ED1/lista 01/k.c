#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int sto[n];

    for(int i = 0; i < n; i++)
    {
        scanf(" %d", &sto[i]);
    }

    double avg = 0;
    for(int i = 0; i < n; i++)
    {
        avg += sto[i];
    }

    avg /= (double) n;

    int ans[n];

    for(int i = 0; i < n; i++)
    {
        ans[i] = -1;
    }

    for(int i = 0; i < n; i++)
    {
        if( (double) sto[i] > avg)
        {
            ans[i] = sto[i];
        }
    }

    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(!flag && ans[i] > -1)
        {
            printf("%d", ans[i]);
            flag = 1;
        } 
        else if(ans[i] > -1) printf(" %d", ans[i]);
    }

    if(!flag) printf("0\n");
    else printf("\n");

    return 0;
}