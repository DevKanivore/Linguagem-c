#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef struct {
    int valor[N];
    int fim, inicio;
}fila;

fila *inicializando();
int filaVazia(fila *f);
int filaCheia(fila *f);
int removerDaFila(fila *f);
void inserirNaFila(fila *f, int dado);
void mostrarFila(fila *f);
void troca(fila *f1, fila *f);
void preenche(fila *f);
void Bubbleshort(fila *f);

int main(){

    srand(time(NULL));

    fila *teste = inicializando();


    preenche(teste);

    printf("\n");

    mostrarFila(teste);

    printf("\n");
    Bubbleshort(teste);

    mostrarFila(teste);

    return 0;
}

void troca(fila *f, fila *f2){

    int temp;

    temp = f->valor[f->inicio];
    f->valor[f->inicio] = f2->valor[f->inicio];
    f2->valor[f->inicio] = temp;
}

void preenche(fila *f){
    int i;
    for(i = f->inicio; i < N; i ++){
        f->valor[i] = (rand() % 100);
        f->fim++;
    }
}

void Bubbleshort(fila *f){
    
    fila *aux;

    for (int i = f->inicio; i < f->fim -1; i++){
        for (int j = f->inicio + 1; i < f->fim -i; i++){
            troca(f, aux);
        }
    }
}


fila *inicializando(){
    fila *f = (fila *)malloc(sizeof(fila));

    f->inicio = 0;
    f->fim = 0;
}

int filaVazia(fila *f){
    return f->inicio == f->fim;
}
int filaCheia(fila *f){
    return f->fim == N;
}

void inserirNaFila(fila *f, int dado){
    if(filaCheia(f)){
        printf("Fila cheia\n");
        return;
    }
    f->valor[f->fim] = dado;
    f->fim++;
}

int removerDaFila(fila *f){
    if(filaCheia(f)){
        printf("Fila vazia\n");
        return -1;
    }
    return f->valor[f->inicio];
    f->inicio++;
}

void mostrarFila(fila *f){
    int i;
    if(filaVazia(f)){
        printf("Fila vazia\n");
    }else{
        printf("Fila:\n");
    }
    for (i = f->inicio; i < f->fim; i++){
        printf("%2d\n", f->valor[i]);
    } 
}