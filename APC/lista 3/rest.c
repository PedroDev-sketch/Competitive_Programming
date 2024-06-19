#include <stdio.h>

int main()
{
    int r, cod, gra;
    int bestc = 0, bestg = 0, day = 1;
    while(scanf("%d", &r) != EOF)
    {
        for(int i = 0; i < r; i++)
        {
            scanf("%d %d", &cod, &gra);
            if(bestg == 0)
            {
                bestc = cod;
                bestg = gra;
            }
            else if(bestg < gra)
            {
                bestc = cod;
                bestg = gra;
            }
            else if(bestg == gra && bestc > cod)
            {
                bestc = cod;
                bestg = gra;
            }
        }
        printf("Dia %d\n%d\n\n", day, bestc);
        bestc = 0;
        bestg = 0;
        day++;
    }
    return 0;
}