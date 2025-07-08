#include <stdio.h>

int coluna = 0;
int linha = 0;

char mapa[1003][1003];
int visitado[1003][1003] = {0}; 

int movx[] = {-1, 1, 0, 0};
int movy[] = {0, 0, -1, 1};

int patinhos;

int recursive_dfs(int x, int y)
{
    visitado[x][y] = 1;

    //debug
    //mapa[x][y] = 'P';

    for(int i = 0; i < 4; i++)
    {
        int novox = x + movx[i];
        int novoy = y + movy[i];

        if(!visitado[novox][novoy] && novox >= 0 && novoy >= 0 && novox < linha && novoy < coluna && (mapa[novox][novoy] == '_' || mapa[novox][novoy] == 'o'))
        {
            if(mapa[novox][novoy] == 'o')
            {
                patinhos--;
            }
            recursive_dfs(novox, novoy);
        }
    }
}

int main()
{
    scanf("%d", &patinhos);

    int comp = patinhos;

    while(scanf("%s", mapa[linha]) != EOF)
    {
        linha++;
    }

    for(int i = 0; i < 1003; i++)
    {
        if(mapa[0][i] == '\0')
        {
            coluna = i;
            break;
        }
    }

    int x, y, stop = 0;
    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            if(mapa[i][j] == 'S')
            {
                x = i;
                y = j;
                stop = 1;
                break;
            }

            else if(mapa[i][j] == '\0') break;
        }
        if(stop) break;
    }

    recursive_dfs(x, y);

    if(comp == patinhos) printf("Nenhum morreu :(\n");
    else if(patinhos <= 0) printf("Todos morreram :)\n");
    else printf("%d encontraram o vovo\n", patinhos);

    //debug
    /* for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    } */
 
    return 0;
}