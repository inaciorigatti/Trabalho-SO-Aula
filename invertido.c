#include <stdio.h>

#define TOTAL_FRAMES 10 

typedef struct {
    int pid;
    int pagina_logica;
    int ativo;
} FrameFisico;

FrameFisico RAM[TOTAL_FRAMES];

void inicializar_ram() {
    for(int i = 0; i < TOTAL_FRAMES; i++) RAM[i].ativo = 0;
}

void mapear_invertida(int pid, int pag, int frame) {
    if (frame < TOTAL_FRAMES) {
        RAM[frame].pid = pid;
        RAM[frame].pagina_logica = pag;
        RAM[frame].ativo = 1;
    }
}

int buscar_invertida(int pid, int pag) {

    for (int i = 0; i < TOTAL_FRAMES; i++) {
        if (RAM[i].ativo && RAM[i].pid == pid && RAM[i].pagina_logica == pag) {
            return i; 
        }
    }
    return -1;
}

int main() {
    inicializar_ram();
    printf("--- Teste: Tabela Invertida ---\n");
    
    mapear_invertida(101, 5, 2); // Processo 101, Pag 5 no Frame 2
    mapear_invertida(202, 5, 8); // Processo 202, Pag 5 no Frame 8

    printf("Busca PID 101, Pag 5: Frame %d (Esperado: 2)\n", buscar_invertida(101, 5));
    printf("Busca PID 202, Pag 5: Frame %d (Esperado: 8)\n", buscar_invertida(202, 5));
    printf("Busca Inexistente: %d (Esperado: -1)\n", buscar_invertida(101, 99));
    return 0;
}