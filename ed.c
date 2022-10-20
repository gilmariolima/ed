#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int id;
    int sexo;
    int num_filhotes;

    struct no * ant;
    struct no * prox;
}no;

no * inicio = NULL;
int tam = 0;

void add(int id, int sexo, int num_filhotes){
    no * novo = malloc(sizeof(no));
    novo->id = id;
    novo->sexo = sexo;
    novo->num_filhotes = num_filhotes;

    novo->ant = NULL;
    novo->prox = NULL;

    if(tam == 0){
        inicio = novo;
        novo->prox = novo;
        novo->ant = novo;
    }else{
        if(tam == 1){
            inicio->prox = novo;
            inicio->ant = novo;
            novo->prox = inicio;
            novo->ant = inicio;
        }else{
            novo->prox = inicio;
            novo->ant = inicio->ant;
            inicio->ant->prox = novo;
            inicio->ant = novo;
        }
    }
    tam++;
}

void ver(){
    no * aux = inicio;
    for(int i=0; i<tam; i++){
        printf("id: %d\n", aux->id);
        aux = aux->prox;
    }
    printf("ant: %d", inicio->ant->id);
}

int main(){
    add(1, 1, 1);
    add(2, 1, 1);
    add(3, 1, 1);
    add(4, 0, 0);
    ver();
    return 0;
}