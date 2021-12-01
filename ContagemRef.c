#include <stdio.h>
#include <stdlib.h>

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
    printf("\n%d\n",&heap[pos].val);
    pos++;
    return &heap[pos-1].val;
}

void atrib2(int *a, int *b){
    int enda= *a;
    int endhp= heap;
    int t=sizeof(hp);

    int p=(endhp - enda)/t;

    heap[p].ct--;
    *a=*b;
}

int main(){
    //Iniciando heap
    IniciarHeap();

    //malloc2
    //printf("Maloc do V: \n");
    int *v=malloc2(sizeof(int));
    *v=13;
    /*
    printf("\n%d\n",v);
    printf("\n%d\n",*v);
    printf("\n%d\n",heap[0].val);
    printf("\n%d\n\n",heap[0].ct);*/

    *v=15;
    /*
    printf("\nV=15\n");
    printf("\n%d\n",v);
    printf("\n%d\n",*v);
    printf("\n%d\n",heap[0].val);
    printf("\n%d\n\n",heap[0].ct);


    printf("Maloc do W: \n");*/
    int *w = malloc2(sizeof(int));
    *w=26;

    /*printf("\n%d\n",w);
    printf("\n%d\n",*w);
    printf("\n%d\n",heap[1].val);
    printf("\n%d\n\n",heap[1].ct);*/


    atrib2(&v,&w);
    printf("\n%d\n\n",heap[0].ct);
    /*printf("&V=%d &W=%d ",v,w);

    printf("V=%d W=%d ",*v,*w);*/
    
}