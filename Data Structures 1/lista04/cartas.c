#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* cabeca;
    No* cauda;
    int tamanho;
} Fila;

Fila* cria_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) {
        exit(1);
    }
    f->cabeca = NULL;
    f->cauda = NULL;
    f->tamanho = 0;
    return f;
}

void enfileirar(Fila* f, int valor) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->prox = NULL;

    if (f->cauda != NULL) {
        f->cauda->prox = novo_no;
    }
    f->cauda = novo_no;

    if (f->cabeca == NULL) {
        f->cabeca = novo_no;
    }
    f->tamanho++;
}

int desenfileirar(Fila* f) {
    if (f->cabeca == NULL) {
        return -1;
    }

    No* no_removido = f->cabeca;
    int valor_retornado = no_removido->valor;

    f->cabeca = f->cabeca->prox;

    if (f->cabeca == NULL) {
        f->cauda = NULL;
    }

    free(no_removido);
    f->tamanho--;
    return valor_retornado;
}

int main() {
    int n;
    scanf("%d", &n);

    Fila* baralho = cria_fila();
    for (int i = 1; i <= n; i++) {
        enfileirar(baralho, i);
    }
    
    int* cartas_descartadas = (int*) malloc((n - 1) * sizeof(int));
    int contador_descartadas = 0;

    while (baralho->tamanho >= 2) {
        cartas_descartadas[contador_descartadas++] = desenfileirar(baralho);

        if (baralho->tamanho >= 1) {
            int carta_movida = desenfileirar(baralho);
            enfileirar(baralho, carta_movida);
        }
    }

    printf("Cartas descartadas: ");
    for (int i = 0; i < contador_descartadas; i++) {
        printf("%d", cartas_descartadas[i]);
        if (i < contador_descartadas - 1) {
            printf(", ");
        }
    }
    printf("\n");

    printf("Carta restante: %d\n", baralho->cabeca->valor);

    free(cartas_descartadas);
    free(baralho->cabeca);
    free(baralho);
    
    return 0;
}