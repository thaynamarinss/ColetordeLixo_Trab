#include <stdio.h>
#include <stdlib.h>

typedef struct hp{
    int val;
    int ct;
}hp;
hp *heap;

void IniciarHeap(){
    heap=(hp *) malloc(sizeof(hp));
    heap->ct=0;
}
int add=0;

int *malloc2(int tam){
    heap= realloc(heap, sizeof(hp)*1);
    heap[add].ct++;
    printf("\n%d\n",&heap[0].val);
    return &heap[0].val;
}

int main(){
    //Iniciando heap
    IniciarHeap();

    int *v=malloc2(sizeof(int));
    *v=13;
    printf("\n%d\n",v);
    printf("\n%d\n",*v);
    printf("\n%d\n",heap[0].val);
    
}