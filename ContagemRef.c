#include <stdio.h>
#include <stdlib.h>

typedef struct hp{
    int valor;
    int ct;
}hp;
hp *heap;//criando o heap do tipo hp, com valor e contador
int pos=0;//variável posição armazena o tamanho do heap, e também utilizado para se basear onde deve ser feita a inserção no heap


/**
 * malloc2
 *
 * aloca espaço no heap
 *
 * @return int*
 * ponteiro para o valor do elemento do heap
 */
int *malloc2(){
    heap=(hp *) realloc(heap,sizeof(hp));
    heap[pos].ct=1;
    pos++;
    return &heap[pos-1];
}

/**
 * atrib2
 *
 * Ela atribui o ponteiro do apontador para o receptor, diminuindo o contador de referência do apontador
 * e caso necessário coletando o lixo
 *
 * @param apontador ponteiro que agora apontará para o receptor
 * @param receptor ponteiro que irá ser apontado pelo apontador
 */
void atrib2(int *apontador, int *receptor){
    //Pegando endereço do apontador e o tamanho em bytes de cada "casa" do vetor
    int AdressApontador=*apontador;
    int AdressReceptor=*receptor;
    int AdressHeap= heap;
    int tamanho=sizeof(hp);
    int pA=(AdressApontador - AdressHeap) / tamanho;
    int pR=(AdressReceptor - AdressHeap) / tamanho;

    heap[pA].ct--;
    heap[pR].ct++;

    if(heap[pA].ct==0){
        //Armazenando as informações do receptor para o caso de houver uma alteração
        int count=heap[pR].ct;
        int val=heap[pR].valor;

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

/**
 * ColetordeLixo
 *
 * Elimina Locais de memórias que não estão sendo referênciados, ou seja, com seu contador=0
 *
 * @param int p - A partir dessa "casa" p que vai começar a ser feita a coleta
 */
void ColetordeLixo(int p){
    for(int i=p;i<pos-1;i++)
        heap[i]=heap[i-1];
    pos--;
    heap=(hp*) realloc(heap,sizeof(hp)*pos);
}


/**
 * PrintaHeap
 * Mostra as casas do heap
 */
void PrintaHeap(){
    for(int i=0;i<pos;i++){
        printf("Heap[%d] End:%d ct:%d Valor:%d\n",i,&heap[i],heap[i].ct,heap[i].valor);
    }
}


int main(){
    printf("_________________________Coletor de lixo em C_________________________\n\n");
    int *v=malloc2();
    *v=10;
    printf("*V criado e impressao do heap:\n");
    PrintaHeap();
    int *w=malloc2();
    *w =20;
    printf("\n*W criado e impressao do heap:\n");
    PrintaHeap();
    //Esses printfs foram utilizados para se ter noção dos valores e dos ponteiro para onde as variáveis estão apontando
    printf("\n->Antes de chamar a funcao atib2(&w,&v)\n");
    printf("\nVal_V: %d Pont_V: %d\n",*v,v);
    printf("\nVal_W: %d Pont_W: %d\n",*w,w);
    atrib2(&w, &v);
    printf("\n->Depois de chamar a funcao atib2(&w,&v)\n");
    printf("\n->Val_V: %d Pont_V: %d\n",*v,v);
    printf("\n->Val_W: %d Pont_W: %d\n",*w,w);
    printf("\nO heap ficou da seguinte forma: ");
    PrintaHeap();
    int *c=malloc2();
    *c=26;
    printf("\n->Antes de chamar a funcao atib2(&c,&v)\n");
    printf("\nVal_V: %d Pont_V: %d\n",*v,v);
    printf("\nVal_W: %d Pont_W: %d\n",*w,w);
    printf("\nVal_C: %d Pont_C: %d\n",*c,c);
    atrib2(&c, &v);
    printf("\n->Depois de chamar a funcao atib2(&c,&v)\n");
    printf("\nVal_V: %d Pont_V: %d\n",*v,v);
    printf("\nVal_W: %d Pont_W: %d\n",*w,w);
    printf("\nVal_C: %d Pont_C: %d\n",*c,c);
    printf("\nO heap ficou da seguinte forma: ");
    PrintaHeap();

    return 0;
}
