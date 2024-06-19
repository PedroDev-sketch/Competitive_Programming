#include <stdio.h>

void maior(int a, int b, int c)
{
    if(a > b && a > c) printf("A");
    else if(b > a && b > c) printf("B");
    else if(c > a && c > b) printf("C");
    else if(a > b && a == c) printf("A e C");
    else if(a == b && a > c) printf("A e B");
    else if(b > a && b == c) printf("B e C");
    else if(a == b && a == c) printf("A, B e C");
}

int main()
{
    int juiz;
    scanf("%d", &juiz);
    int nota[3][juiz];
    int A = 0, B = 0, C = 0;

    for(int i = 0; i < juiz; i++)
    {
        int notaA, notaB, notaC;
        scanf("%d %d %d", &notaA, &notaB, &notaC);
        A += notaA;
        B += notaB;
        C += notaC;
    }

    maior(A, B, C);
    return 0;
}