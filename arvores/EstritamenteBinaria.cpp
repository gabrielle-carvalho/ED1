#include<iostream>
struct nodo{
    int info;
    struct nodo *esq, *dir;
};

class Arvore{
    public:
    nodo *raiz;
    nodo *inserir(nodo *raiz, int n); // 
    void emOrdem(nodo *raiz); // esquerda | raiz | direita
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
    // return;
}

void emOrdem(nodo *raiz){
    if(raiz==nullptr) return;
    emOrdem(raiz->esq); // vai ate o ultimo elemento existente na esquerda e coloca na fila
    std::cout<< raiz->info <<std::endl; // qunado nao ha mais elementos a esquerda, comeca a printar
    emOrdem(raiz->dir); //chama os valores pela ireita ate o fim, recursividade dnv
}

bool EstritamenteBinaria(nodo *raiz){
    if(raiz==nullptr)
        return true; //na ultima vez se for nulo ele retorna true indicando que é estritamente binaria, garantindo que todos os elementos cumpram essa regra
    if((raiz->esq==nullptr&&raiz->dir==nullptr) || (raiz->esq!=nullptr&&raiz->dir!=nullptr))
        return (EstritamenteBinaria(raiz->esq)) && (EstritamenteBinaria(raiz->dir));
    else
        return false;
}

Nodo *retirar(Nodo *raiz, int n){
    Nodo *aux;
    if(raiz==nullptr)
        return raiz;
    if(n>raiz->info)
        raiz->dir=retirar(raiz->dir, n);
    else if(n<raiz->info)
        raiz->esq=retirar(raiz->dir, n);
    else{
        if(raiz->esq==nullptr){
            aux=raiz;
            raiz=raiz->dir;
            delete aux;
            return raiz; ///volta e se linka com o ultimo elemento ao seu lado
        }
        else if(raiz->dir == nullptr){
            aux=raiz;
            raiz=raiz->esq;
            delete aux;
            return raiz;
        }
        else{
            raiz->dir=substituir(raiz, raiz->dir); //pela direita pois é sucessor
        }
    }
}

Nodo *substituir(Nodo*raiz, Nodo *sucessor){
    Nodo *aux;
    if(sucessor->esq!=nullptr)
        sucessor->esq=substituir(raiz, sucessor->esq); //ele começa a percorrer a esquerda ate o final pra encontrar o menor
    else{
        raiz->info=sucessor->info;
        aux=sucessor;
        sucessor=sucessor->dir;
        delete aux;
        return sucessor;

    }
}


int main(){
    Arvore tree;
    tree.raiz=inserir(tree.raiz, 10); // pesquisar porque é chamdo assim, passando tree.raiz
}