// Considere uma árvore binária de pesquisa que possui em cada nó elementos inteiros.  Escreva 
// uma função recursiva, em C, para criar uma nova árvore binária de pesquisa contendo apenas 
// os nós-folhas da primeira árvore.

#include<iostream>

struct nodo{
    int info;
    nodo *esq, *dir;
};

class Arvore{
    public:
    nodo * raiz;
    Arvore();
    nodo *inserir(nodo *raiz, int n);
    nodo* retirar(nodo *raiz, int n);
    void emOrdem(nodo *raiz);
    void arvoreFolhas(nodo *raiz, Arvore &novaArvore);
};

Arvore::Arvore(){
    raiz=nullptr;
}

nodo *Arvore::inserir(nodo *raiz, int n){
    if(raiz==nullptr){
        raiz=new nodo();
        raiz->info=n;
        raiz->esq=nullptr;
        raiz->dir=nullptr;
        return raiz;
    }
    if(n>raiz->info){
        raiz->dir=inserir(raiz->dir, n);
    }
    else if(n<raiz->info){
        raiz->esq=inserir(raiz->esq, n);
    }
    else{
        std::cout<<"Número igual a algum que esta na lista. RETORNANDO"<<std::endl;
        return raiz;
    }
    return raiz;
}

void Arvore::emOrdem(nodo *raiz) {
    if (raiz == nullptr) return;
    emOrdem(raiz->esq);
    std::cout << raiz->info << " ";
    emOrdem(raiz->dir);
}

void Arvore::arvoreFolhas(nodo *raiz, Arvore &novaArvore){
    if(raiz==nullptr){
        return;
    }
    if(raiz->esq==nullptr && raiz->dir==nullptr){
        novaArvore.raiz=novaArvore.inserir(novaArvore.raiz, raiz->info);
        return;
    }
    arvoreFolhas(raiz->esq, novaArvore);
    arvoreFolhas(raiz->dir, novaArvore);
}

int main() {
    Arvore original;
    original.raiz = original.inserir(original.raiz, 10);
    original.raiz = original.inserir(original.raiz, 5);
    original.raiz = original.inserir(original.raiz, 3);
    original.raiz = original.inserir(original.raiz, 7);
    original.raiz = original.inserir(original.raiz, 20);

    Arvore nova;
    original.arvoreFolhas(original.raiz, nova);

    nova.emOrdem(nova.raiz); // deve imprimir 3 7 20

    return 0;
}

