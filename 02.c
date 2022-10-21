#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char * heroi;
    int num_filmes;
    int dias_descanco;
    
    struct no * prox;
}no;

no * inicio = NULL;
no * fim = NULL;
int tam = 0;

void adicionar(char * heroi, int num_filmes){
    no * novo = malloc(sizeof(no));
    novo->heroi = heroi;
    novo->num_filmes = num_filmes;
    novo->dias_descanco = 5 * num_filmes;
    novo->prox = NULL;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }else if(inicio->num_filmes < num_filmes){
        novo->prox = inicio;
        inicio = novo;
    }else if(fim->num_filmes > num_filmes){
        fim->prox = novo;
        fim = novo;
    }else{
        no * aux = inicio;
        while(aux != NULL){
            if(aux->prox->num_filmes < num_filmes){
                novo->prox = aux->prox;
                aux->prox = novo;
                return;
            }
            aux = aux->prox;
        }
    }
    tam++;
}

void ver(){
    no * aux = inicio;
    for(int i=0; i<=tam; i++){
        printf("%s - %d filmes - %d dias\n", aux->heroi, aux->num_filmes, aux->dias_descanco);
        aux = aux->prox;
    }
}

char * remover(){
    char * nome_removido;
    no * lixo = inicio;
    inicio = inicio->prox;
    nome_removido = lixo->heroi;
    free(lixo);
    return nome_removido;
}

int main(){
    adicionar("Homem aranha", 5);
    adicionar("Homem de ferro", 10);
    adicionar("Hulk", 4);
    adicionar("dr", 6);
    adicionar("viuva", 7);

    ver();
    printf("\nremovido %s\n\n", remover());
    ver();
    return 0;
}