#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct hp{
    int val;
    int ct;
}hp;
hp *heap;

void IniciarHeap(){
    heap=(hp *) malloc(sizeof(hp));
}
int pos=0;

int *malloc2(int tam){
    heap= realloc(heap, sizeof(hp)*1);
    heap[pos].ct=1;
    printf("Print - Func Malloc2 heap[%d]%d\n",pos, &heap[pos].val);
    pos++;
    return &heap[pos-1].val;
}
void PrintaHeap(){
    for(int i=0;i<pos;i++){
        printf("Heap[%d], Adress: %d val=%d ct=%d\n",i,&heap[i], heap[i].val,heap[i].ct);
    }printf("\n");
}

// | w | c |
void ColetaLixo(int p){

    for(int i=p;i<pos-1;i++){
        heap[i]=heap[i+1];
    }
    free(&heap[pos]);
    pos--;
    heap = realloc(heap,sizeof(hp)*pos-1);

}


void atrib2(int *a, int *b){
    for(int i=0;i<pos;i++){
        printf("(Print 1 - Func atrib2) Heap[%d] Adress: %d val=%d\n",i, &heap[i], heap[i].val);
    }
    int AdressA = a;
    int AdressHeap = heap;
    int t = sizeof(hp);

    int p = (AdressHeap - AdressA)/t;

    heap[p].ct--;
    *a=*b;

    for(int i=0;i<pos;i++){
        printf("(Print 2 - Func atrib2 antes da coleta) Endereço de Heap[%d]: %d val=%d\n",i, &heap[i], heap[i].val);
    }
    if(heap[p].ct==0) ColetaLixo(p);

    for(int i=0;i<pos;i++){
        printf("(Print 3 - Func atrib2 pós coleta) Endereço de Heap[%d]: %d val=%d\n",i, &heap[i], heap[i].val);
    }
}

int main(){
	setlocale(LC_CTYPE, "Portuguese");

    //Iniciando heap
    IniciarHeap();

    //malloc2
    //printf("Maloc do V: \n");
    int *v=malloc2(sizeof(int));
    *v=10;
    /*
    printf("\nV=15\n");
    printf("\n%d\n",v);
    printf("\n%d\n",*v);
    printf("\n%d\n",heap[0].val);
    printf("\n%d\n\n",heap[0].ct);


    printf("Maloc do W: \n");*/
    int *w = malloc2(sizeof(int));
    *w=15;

    int *c = malloc2(sizeof(int));
    *c=20;
    /*printf("\n%d\n",w);
    printf("\n%d\n",*w);
    printf("\n%d\n",heap[1].val);
    printf("\n%d\n\n",heap[1].ct);*/

    printf("\n&V=%d &W=%d\n",v,w);
    printf("\n&V=%d &W=%d\n",*v,*w);
    PrintaHeap();
    atrib2(&v,&w);
    PrintaHeap();
    printf("\n&V=%d &W=%d\n",v,w);
    printf("\n&V=%d &W=%d\n",*v,*w);

    int *d = malloc2(sizeof(int));
    *d=25;
}
