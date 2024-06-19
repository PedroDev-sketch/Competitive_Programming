#include <stdio.h>

int repetidos(int v[10000], int qtd, int index)
{
    int count = 0;
    for(int i = 0; i < qtd; i++)
    {
        if(v[i] == v[index] && i != index) count++;
    }
    return count;
}