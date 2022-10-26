#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void troca(int *x, int *y);
void imprime(int vet[]);
void preencher(int vet[], int N);
void bubble(int vet[]);
void select(int vet[]);
void insertion(int vet[]);
void quiksort(int vet[]);

int main(){
    
    srand(time(NULL));

    int vetor[MAX];

    preencher(vetor, 40);

    imprime(vetor);
    
    // bubble(vetor);
    // select(vetor);
   //insertion(vetor);

    imprime(vetor);

    return 0;
}

void troca(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void imprime(int vet[]){
    int i;
    for ( i = 0; i < MAX; i++){
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}

void preencher(int vet[], int N){
    int i;
    for ( i = 0; i < N; i++){
        vet[i] = (rand() % N) + 1;
    }
}

void bubble(int vet[]){
    int i, j;
    for (i = 0; i < MAX - 1; i++){
        for (j = 1; j < MAX - i; j++){
            if(vet[j-1] > vet[j]){
                troca(&vet[j], &vet[j - 1]);
            }
        }       
    }
}

void select(int vet[]){
    int i, j, min;

    for (i = 0; i < MAX - 1; i++){
        min = i;
        for (j = i + 1; j < MAX; j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        troca(&vet[min], &vet[i]);
    }
    
}

void insertion(int vet[]){
    int i, j, aux;

    for (i = 1; i < MAX; i++){
        aux = vet[i];
        for (j = i - 1; j >= 0 && aux < vet[j]; j--){
            vet[j + 1] = vet[j];
        }
        vet[j + 1] = aux;
    }
}

