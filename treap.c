#include <stdio.h>
#include <stdlib.h>

#define MAXCHAVE 100

typedef struct treap{
    int info;
    int chave;
    struct treap *direita;
    struct treap *esquerda;
}treap;

treap *novoNo(int v, int maxChave);
treap *inserir(treap *raiz, int v);
void exibeTreap(treap *raiz, int espaco);
void destroiTreap(treap *raiz);

int main(){
    treap *arvore = NULL;

    arvore = inserir(arvore, 4);
    arvore = inserir(arvore, 7);
    arvore = inserir(arvore, 6);
    arvore = inserir(arvore, 2);
    arvore = inserir(arvore, 3);
    arvore = inserir(arvore, 5);
    arvore = inserir(arvore, 1);

    exibeTreap(arvore, 0);

    destroiTreap(arvore);
    return 0;
}


treap *novoNo(int v, int maxChave){
    treap *novo = (treap *)malloc(sizeof(treap));
    novo->info = v;
    novo->chave = rand() % maxChave;
    novo->direita = NULL;
    novo->esquerda = NULL;

    return novo;
}

treap *inserir(treap *raiz, int v){
    if(!raiz)
        return novoNo(v, MAXCHAVE);
    else if(v > raiz->info)
        raiz->direita = inserir(raiz->direita, v);
    else if(v <= raiz->info)
        raiz->esquerda = inserir(raiz->esquerda, v);
    return raiz;
}

void exibeTreap(treap *raiz, int espaco){
    int i;
    if(raiz){
        exibeTreap(raiz->direita, espaco + 1);
        for(i = 0; i < espaco ;i++)
            printf("      ");
        printf("%d(%d)\n", raiz->info, raiz->chave);
        exibeTreap(raiz->esquerda, espaco + 1);
    }
}

void destroiTreap(treap *raiz){
    //Travessia pós-ordem de árvore
    if(raiz){
        destroiTreap(raiz->direita);
        destroiTreap(raiz->esquerda);
        free(raiz);
    }
}