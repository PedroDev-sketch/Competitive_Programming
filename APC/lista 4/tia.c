#include <stdio.h>

int main()
{
    int n, m, a, k;
    char senha[1001];
    scanf("%d %d %d %d", &n, &m, &a, &k);
    scanf("%s", senha);
    for(int i = 0; senha[i] != '\0'; i++)
    {
        if(senha[i] >= 48 && senha[i] <= 57) k--;
        else if(senha[i] >= 65 && senha[i] <= 90) a--;
        else if(senha[i] >= 97 && senha[i] <= 122) m--;
        n--;   
    }
    if(n > 0 || m > 0 || a > 0 || k > 0)
    {
        printf("Ufa :)\n");
    }
    else printf("Ok =/\n");;
    return 0;
}