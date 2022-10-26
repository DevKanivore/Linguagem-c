#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10

void troca(int *x, int *y);
void preencher(int vet[], int MAX);
void imprime(int vet[]);
void bubble(int vet[]);
void select(int vet[]);

int main(){

    srand(time(NULL));

    int lol[NUM];

    preencher(lol, 40);
    imprime(lol);
    printf("\n");
    select(lol);
    imprime(lol);

    return 0;
}


void troca(int *x, int *y){

    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

void imprime(int vet[]){
    for (int i = 0; i < NUM; i++){
        printf("%d ", vet[i]);
    }
        
}

void preencher(int vet[], int MAX){
    int i;
    for (i = 0; i < MAX; i++){
        vet[i] = (rand () % MAX) + 1;
    }
    
}

void bubble(int vet[]){
    //variaveis pra pecorrer o loop
    int i, j;
    //primeiro for
    for(i = 0; i < NUM - 1; i++){
        for(j = 1; j < NUM - i; j++){
            if(vet[j - 1] > vet[j]){
                troca(&vet[j], &vet[j-1]);
            }
        }
    }
}

void select(int vet[]){
    int i, j, min;
    for (i = 0; i < NUM - 1; i++){
        min = i;
        for (j = i + 1; i < NUM; j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        troca(&vet[min], &vet[i]);
    }    
}