#include <stdio.h>
#include <stdlib.h>

typedef struct hp{
    int valor;
    int ct;
}hp;
hp *heap;
int pos=0;

int *malloc2(int tam){
    heap=(hp *) realloc(heap,sizeof(hp));
    heap[pos].ct=1;
    pos++;
    return &heap[pos-1];
}

void atrib2(int *apontador, int *receptor){
    //Pegando endereço do apontador e o tamanho em bytes de cada "casa" do vetor
    int AdressApontador=*apontador;
    int AdressReceptor=*receptor;
    int AdressHeap= heap;
    int tamanho=sizeof(hp);
    int pA=(AdressApontador - AdressHeap) / tamanho;
    int pR=(AdressReceptor - AdressHeap) / tamanho;
    
    heap[pA].ct--;

    int count=heap[pR].ct + 1;
    printf("==%d==",count);
    int val=heap[pR].valor;

    if(heap[pA].ct==0){
        ColetordeLixo(pA);
        if(pR>pA){
            heap[pR-1].ct=count;
            heap[pR-1].valor=val;
            *receptor-=tamanho;
        }else{
            heap[pR].ct=count;
            heap[pR].valor=val;
        }
    }
    *apontador=*receptor;
}

void ColetordeLixo(int p){
    for(int i=p;i<pos-1;i++)
        heap[i]=heap[i-1];
    pos--;
    heap=(hp*) realloc(heap,sizeof(hp)*pos);
}

void PrintaHeap(){
    for(int i=0;i<pos;i++){
        printf("Heap[%d] End:%d ct:%d Valor:%d\n",i,&heap[i],heap[i].ct,heap[i].valor);
    }
}


int main(){
    int *v=malloc2(sizeof(int));
    *v=10;
    PrintaHeap();
    int *w=malloc2(sizeof(int));
    *w =20;
    PrintaHeap();
    printf("\n%d %d %d\n",&v,*v,v);
    printf("\n%d %d %d\n",&w,*w,w);
    atrib2(&w, &v);
    PrintaHeap();
    printf("\n%d %d %d\n",&v,*v,v);
    printf("\n%d %d %d\n",&w,*w,w);
    int *c=malloc2(sizeof(int));
    *c=26;
    printf("\n%d %d %d\n",&v,*v,v);
    printf("\n%d %d %d\n",&w,*w,w);
    printf("\n%d %d %d\n",&c,*c,c);
    atrib2(&c, &v);
    printf("\n%d %d %d\n",&v,*v,v);
    printf("\n%d %d %d\n",&w,*w,w);
    printf("\n%d %d %d\n",&c,*c,c);
    PrintaHeap();
    return 0;
}