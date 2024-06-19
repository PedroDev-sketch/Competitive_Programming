#include <stdio.h>

double fogo(int nivel)
{
    double dano;
    if(nivel == 1)
    {
        dano = 2.0;
    }
    else if(nivel == 2)
    {
        dano = 3.0;
    }
    else dano = 5.0;
    return dano;
}

double agua(int nivel)
{
    double dano;
    if(nivel == 1)
    {
        dano = 1.0;
    }
    else if(nivel == 2)
    {
        dano = 2.5;
    }
    else dano = 4.0;
    return dano;
}

double terra(int nivel)
{
    double dano;
    if(nivel == 1)
    {
        dano = 2.5;
    }
    else if(nivel == 2)
    {
        dano = 5.5;
    }
    else dano = 7.0;
    return dano;
}

double calculaVantagem(int tipoPlayer, int tipoCPU)
{
    double answer;
    if(tipoPlayer == 2)
    {
        if(tipoCPU == 1) answer = 2.0;
        else if(tipoCPU == 2) answer = 1.0;
        else answer = 0.5;
    }

    else if(tipoPlayer == 3)
    {
        if(tipoCPU == 1) answer = 0.5;
        else if(tipoCPU == 2) answer = 2.0;
        else answer = 1.0;
    }

    else if(tipoPlayer == 1)
    {
        if(tipoCPU == 1) answer = 1.0;
        else if(tipoCPU == 2) answer = 0.5;
        else answer = 2.0;
    }
    return answer;
}

double calculaDano(int tipoPlayer, int nivelPlayer, int tipoCPU, double defesaCPU)
{
    double dano = 100;
    if(tipoPlayer == 2)
    {
        dano *= fogo(nivelPlayer);
    }

    else if(tipoPlayer == 3)
    {
        dano *= agua(nivelPlayer);
    }

    else if(tipoPlayer == 1)
    {
        dano *= terra(nivelPlayer);
    }

    dano *= calculaVantagem(tipoPlayer, tipoCPU);
    dano -= defesaCPU;
    if(dano >= 0) return dano;
    else return 0.000000;
}