#include <stdio.h>

int main()
{
    int n, count, answer;
    char str[100];
    int arr[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", str);
        count = 0;
        while(str[count] != 0)
        {
            count++;
        }
        arr[i] = count;
    }
    for(int i = 0; i < n && arr[i] != 0; i++)
    {
        if(i == 0) answer = arr[i];
        else if(answer < arr[i]) answer = arr[i];
    }
    printf("%d", answer);
    return 0;
}