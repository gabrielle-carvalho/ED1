#include <iostream>

struct nodo{
    int info;
    struct nodo *esq, *dir;
};

class Arvore{
    public:
    nodo *raiz;
    nodo *inserir(nodo *raiz, int n); // 
    void emOrdem(nodo *raiz); // esquerda | raiz | direita
    void posOrdem(nodo *raiz);
    void preOrdem(nodo *raiz);
};

Arvore :: Arvore (){
    raiz=nullptr;
}

nodo *inserir(nodo *raiz, int n){
    if (raiz==nullptr){
        raiz=new nodo();
        if(raiz==nullptr) exit(1); //nao conseguiu criar a area e nao ha mais nada a fazer
        raiz->info=n;
        raiz->esq=nullptr;
        raiz->dir=nullptr;
        return raiz;
    }
    if(n>raiz->info){ //recursividade!
        raiz->dir = inserir(raiz->dir, n);
    }
    else if (n<raiz->info){
        raiz->esq=inserir(raiz->esq, n);
    }
    else{
        std::cout<<"Número igual a algum que esta na lista. RETORNANDO"<<std::endl;
        return;
    }
    return raiz;
}

void emOrdem(nodo *raiz){
    if(raiz==nullptr) return;
    emOrdem(raiz->esq); // vai ate o ultimo elemento existente na esquerda e coloca na fila
    std::cout<< raiz->info <<std::endl; // qunado nao ha mais elementos a esquerda, comeca a printar
    emOrdem(raiz->dir); //chama os valores pela ireita ate o fim, recursividade dnv
}

void posOrdem(nodo *raiz){
    if(raiz==nullptr) return;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    std::cout<< raiz->info <<std::endl;
}

void preOrdem(nodo *raiz){
    if(raiz==nullptr) return;
    std::cout<< raiz->info <<std::endl; 
    preOrdem(raiz->esq); 
    preOrdem(raiz->dir); 
}

int main(){
    Arvore tree;
    tree.raiz=inserir(tree.raiz, 10); 
}
