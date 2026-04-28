#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_DIRETORIO 1024
#define TAMANHO_TABELA_PAG 1024

typedef struct {
    int frames[TAMANHO_TABELA_PAG];
} TabelaPagina;

TabelaPagina* diretorio[TAMANHO_DIRETORIO] = {NULL};

void mapear_hierarquica(int d_idx, int t_idx, int frame) {
    if (diretorio[d_idx] == NULL) {
        printf("Alocando tabela de segundo nivel para indice %d...\n", d_idx);

        diretorio[d_idx] = (TabelaPagina*)malloc(sizeof(TabelaPagina));

        for(int i = 0; i < TAMANHO_TABELA_PAG; i++) {
            diretorio[d_idx]->frames[i] = -1;
        } 
    }

    diretorio[d_idx]->frames[t_idx] = frame;
}

int buscar_hierarquica(int d_idx, int t_idx) {
    
    if (diretorio[d_idx] == NULL) {
        return -1; 
    }

    return diretorio[d_idx]->frames[t_idx];
}

int main() {
    
    printf("--- Paginacao Hierarquica ---\n");

    mapear_hierarquica(0, 10, 500);
    mapear_hierarquica(5, 20, 750);

    printf("Busca (0,10): %d (Esperado: 500)\n", buscar_hierarquica(0, 10));
    printf("Busca (5,20): %d (Esperado: 750)\n", buscar_hierarquica(5, 20));
    printf("Busca (1,1): %d (Esperado: -1 - Page Fault)\n", buscar_hierarquica(1, 1));

    return 0;
}