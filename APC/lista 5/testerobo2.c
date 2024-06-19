#include <stdio.h>

int main()
{
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    int dir;
    int x, y;
    char instruct;
    while(n != 0 && m != 0 && s != 0)
    {
        int count = 0;
        char mapa[n][m];
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf(" %c", &mapa[i][j]);

                if (mapa[i][j] != '.' && mapa[i][j] != '#' && mapa[i][j] != '*')
                {
                    if (mapa[i][j] == 'N')
                        dir = 0;
                    else if (mapa[i][j] == 'L')
                        dir = 1;
                    else if (mapa[i][j] == 'S')
                        dir = 2;
                    else if (mapa[i][j] == 'O')
                        dir = 3;
                    mapa[i][j] = '.';
                    x = i;
                    y = j;
                }
            }
        }

        for(int i = 0; i < s; i++)
        {
            scanf(" %c", &instruct);
            if(instruct == 'F')
            {
                int newX = x + dx[dir], newY = y + dy[dir];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && mapa[newX][newY] != '#')
                {
                    if(mapa[newX][newY] == '*') 
                    {
                        mapa[newX][newY] = '.';
                        count++;
                    }
                    x = newX;
                    y = newY;
                }
            }
            else if(instruct == 'D')
            {
                dir = (dir + 1) % 4;
            }
            else if(instruct == 'E')
            {
                dir = (dir + 3) % 4;
            }
        }

        printf("%d\n", count);

        scanf("%d %d %d", &n, &m, &s);
    }
    return 0;
}
