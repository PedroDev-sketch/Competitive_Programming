#include <stdio.h>

int main()
{
    int t, pa, pb;
    double ga, gb;
    int temp;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d %lf %lf", &pa, &pb, &ga, &gb);
        ga /= 100, gb /= 100;
        temp = 0;
        while(pa <= pb && temp <= 100)
        {
            pb += pb * gb;
            pa += pa * ga;
            temp++;
        }
        if(temp > 100) printf("Mais de 1 seculo.\n");
        else printf("%d anos.\n", temp);
    }
    return 0;
}