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
        printf("id: %d - sexo: %d - filhotes: %d\n", aux->id, aux->sexo, aux->num_filhotes);
        aux = aux->prox;
    }
}

void remover(int id){
    no * lixo = inicio;
    if(tam == 1 && inicio->id == id){
        inicio = NULL;
        free(lixo);
        tam--;
    }else if(tam == 2){
        if(inicio->id == id){
            inicio = inicio->prox;
            inicio->prox = inicio;
            inicio->ant = inicio;
            free(lixo);
            tam--;
        }else if(inicio->prox->id == id){
            lixo = inicio->prox;
            inicio->prox = inicio;
            inicio->ant = inicio;
            free(lixo);
            tam--;
        }
    }else{
        if(inicio->id == id){
            inicio->prox->ant = inicio->ant;
            inicio->ant->prox = inicio->prox;
            inicio = inicio->prox;
            free(lixo);
            tam--;
        }else{
            no * aux = inicio->prox;
            while(aux->id != id && aux != inicio){
                aux = aux->prox;
            }
            if(aux->id == id){
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
                tam--;
            }
        }
    }

}

int soma_filhotes(){
    int soma = 0;
    no * aux = inicio;
    for(int i=0; i<tam; i++){
        if(aux->sexo == 1)
            soma = soma + aux->num_filhotes;
        aux = aux->prox;
    }
    return soma;
}

int main(){
    add(1,0,2);
    add(2,1,2);
    add(3,1,1);
    add(4,0,1);
    add(5,1,3);

    ver();
    printf("Numero de filhotes: %d", soma_filhotes());
    return 0;
}