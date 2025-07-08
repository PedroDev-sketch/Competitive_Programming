#include <stdio.h>

double calculaVelocidadeMedia(int tA, int tB, double distancia)
{
    double dif = tB - tA;
    dif /= (double) 3600;

    return (distancia / (double) dif);
}

int levouMulta(int tA, int tB, double distancia, double velocidadeMaxima)
{
    int vel = calculaVelocidadeMedia(tA, tB, distancia);
    return (vel > velocidadeMaxima ? 1 : 0);
}