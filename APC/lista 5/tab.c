#include <stdio.h>

int main()
{
    int n, count = 0;
    int mapa[8][8];
    scanf("%d", &n);
    int mov[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &mov[i]);
    }
    int x = 4, y = 3;
    mapa[x][y];

    for(int i = 0; i < n; i++)
    {
        count++;
        if(mov[i] == 1) mapa[x++][y+=2];
        else if(mov[i] == 2) mapa[x+=2][y++];
        else if(mov[i] == 3) mapa[x+=2][y--];
        else if(mov[i] == 4) mapa[x++][y-=2];
        else if(mov[i] == 5) mapa[x--][y-=2];
        else if(mov[i] == 6) mapa[x-=2][y--];
        else if(mov[i] == 7) mapa[x-=2][y++];
        else if(mov[i] == 8) mapa[x--][y+=2];
        if(x == 1 && y == 3) break;
        else if(x == 2 && y == 3) break;
        else if(x == 2 && y == 5) break;
        else if(x == 5 && y == 4) break;
    }

    printf("%d", count);
    return 0;
}