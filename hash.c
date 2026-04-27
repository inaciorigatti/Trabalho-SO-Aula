#include <stdio.h>

#define TAM 10

typedef struct {
    int processo;
    int pagina;
    int frame;
    int ocupado;
} Entrada;


Entrada tabela[TAM];


int hash(int processo, int pagina) {
    return (processo * 31 + pagina) % TAM;
}

void inserir(int processo, int pagina, int frame) {
    int idx = hash(processo, pagina);

    while (tabela[idx].ocupado) {
        idx = (idx + 1) % TAM;
    }

    tabela[idx].processo = processo;
    tabela[idx].pagina = pagina;
    tabela[idx].frame = frame;
    tabela[idx].ocupado = 1;
}

int buscar(int processo, int pagina) {
    int idx = hash(processo, pagina);
    int start = idx;

    while (tabela[idx].ocupado) {
        if (tabela[idx].processo == processo &&
            tabela[idx].pagina == pagina) {
            return tabela[idx].frame;
        }

        idx = (idx + 1) % TAM;

        if (idx == start) break; 
    }

    return -1; 
}


int main() {

    // processo ; pagina ; frame 
    inserir(1, 5, 10);
    inserir(2, 3, 20);
    inserir(1, 8, 30);

    // busca por processo -> pagina -> retorna: frame
    int frame = buscar(1, 5);


    if (frame != -1) {
        printf("Frame: %d\n", frame);
    } else {
        printf("Nao encontrado\n");
    }
        
    return 0;
}
