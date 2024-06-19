#include <stdio.h>

int main()
{
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    while(n != 0 && m != 0 && s != 0)
    {
        int dir = 0;
        int count = 0;
        int axis = 0;
        char mapa[n][m];
        int x, y;

        for(int i = 0; i < n; i++)
        {
            scanf("%s", mapa[i]);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mapa[i][j] == 'N')
                {
                    dir = 1;
                    axis = 1;
                    x = i;
                    y = j;
                    mapa[i][j] = '.';
                    break;
                }
                else if(mapa[i][j] == 'S')
                {
                    dir = -1;
                    axis = 1;
                    x = i;
                    y = j;
                    mapa[i][j] = '.';
                    break;
                }
                else if(mapa[i][j] == 'L')
                {
                    dir = 1;
                    axis = 2;
                    x = i;
                    y = j;
                    mapa[i][j] = '.';
                    break;
                }
                else if(mapa[i][j] == 'O')
                {
                    dir = -1;
                    axis = 2;
                    x = i;
                    y = j;
                    mapa[i][j] = '.';
                    break;
                }
            }
        }

        char instruct[s];
        scanf("%s", instruct);

        for(int i = 0; i < s; i++)
        {
            if(instruct[i] == 'F')
            {
                int newX = x, newY = y;
                if(axis == 2)
                {
                    if(dir == -1) newX--;
                    else newX++;
                }
                else if(axis == 1)
                {
                    if(dir == -1) newY--;
                    else newY++;
                }

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && mapa[newX][newY] != '#')
                {
                    x = newX;
                    y = newY;
                    if(mapa[x][y] == '*') 
                    {
                        mapa[x][y] = '.';
                        count++;
                    }
                }
            }
            else if(instruct[i] == 'D')
            {
                if(dir == 1 && axis == 1)
                {
                    dir = 1;
                    axis = 2;
                }
                else if(dir == 1 && axis == 2)
                {
                    dir = -1;
                    axis = 1;
                }
                else if(dir == -1 && axis == 1)
                {
                    dir = -1;
                    axis = 2;
                }
                else if(dir == -1 && axis == 2)
                {
                    dir = 1;
                    axis = 1;
                }
            }
            else if(instruct[i] == 'E')
            {
                if(dir == 1 && axis == 1)
                {
                    dir = -1;
                    axis = 2;
                }
                else if(dir == -1 && axis == 2)
                {
                    dir = -1;
                    axis = 1;
                }
                else if(dir == -1 && axis == 1)
                {
                    dir = 1;
                    axis = 2;
                }
                else if(dir == 1 && axis == 2)
                {
                    dir = 1;
                    axis = 1;
                }
            }
        }

        printf("%d\n", count);

        scanf("%d %d %d", &n, &m, &s);
    }
    return 0;
}
