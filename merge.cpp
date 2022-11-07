#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void mergeSort(int vet[], int left, int right);
void merge(int vet[], int left, int mid, int right);
void preencher(int vet[]);
void imprime(int vet[]);

int main(){

    srand(time(NULL));

    int vetor[MAX];
    int left = 0;
    int right = 999;

    preencher(vetor);
    imprime(vetor);
    printf("\n");
    mergeSort(vetor, left, right);
    imprime(vetor);
}



void preencher(int vet[]){
    int i;

    for (i = 0; i < MAX; i++){
        vet[i] = (rand() % MAX)+1;
    }    
}

void imprime(int vet[]){
    int i;
    for (i = 0; i < MAX; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
    
}


void mergeSort(int vet[], int left, int right){
    int mid;
    if (left >= right){
        return;
    }

    mid = (left+right)/2;
    mergeSort(vet, left, mid);
    mergeSort(vet, mid+1, right);
    merge(vet, left, mid, right);

}

void merge(int vet[], int left, int mid, int right){

    int i = left, j = mid + 1, k = 0;
    int n = (right - left) + 1;
    int *vaux;
    int flag = 0;

    vaux = (int*)malloc(n * sizeof(int));

    while (i <= mid && j <= right){
       if (vet[i] > vet[j]){
            vaux[k++] = vet[i++];
            flag++;
       }else{
            vaux[k++] = vet[j++];
            flag++;
       }
    }
    
    while (i <= mid){
        vaux[k++] = vet[i++];
    }
    
    while (j <= right){
        vaux[k++] = vet[j++];
    }

    for ( k = 0, i = left; k < n; k++, i++){
        vet[i] = vaux[k];
    }
    printf("\n o numero de trocas e %d\n\n", flag);
    free(vaux);
}