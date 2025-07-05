#include<iostream>
struct nodo {
    int info;
    struct nodo *esq, *dir;
};

class Arvore{
    public:
    nodo * raiz;
    Arvore();
    nodo *inserir(nodo *raiz, int n);
    nodo* retirar(nodo *raiz, int n);
    void emOrdem(nodo *raiz);
    nodo *substituir(nodo*raiz, nodo *sucessor);
    nodo *extremoDireita(nodo *raiz);
    nodo *extremoEsquerda(nodo *raiz);
};

Arvore ::Arvore(){
    raiz=nullptr;
}

nodo* Arvore::inserir(nodo *raiz, int n){
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
        return raiz;
    }
    return raiz;
}

void Arvore::emOrdem(nodo *raiz){
    if(raiz==nullptr) return;
    emOrdem(raiz->esq); // vai ate o ultimo elemento existente na esquerda e coloca na fila
    std::cout<< raiz->info <<std::endl; // qunado nao ha mais elementos a esquerda, comeca a printar
    emOrdem(raiz->dir); //chama os valores pela ireita ate o fim, recursividade dnv
}

nodo* Arvore::retirar(nodo *raiz, int n){
    nodo *aux;
    if(raiz==nullptr)
        return raiz;
    if(n>raiz->info)
        raiz->dir=retirar(raiz->dir, n);
    else if(n<raiz->info)
        raiz->esq=retirar(raiz->esq, n);
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
    return raiz;
}

nodo *Arvore::substituir(nodo*raiz, nodo *sucessor){
    nodo *aux;
    if(sucessor->esq!=nullptr)
        sucessor->esq=substituir(raiz, sucessor->esq); //ele começa a percorrer a esquerda ate o final pra encontrar o menor
    else{
        raiz->info=sucessor->info;
        aux=sucessor;
        sucessor=sucessor->dir;
        delete aux;
        return sucessor;

    }
    return raiz;
}


nodo *Arvore::extremoDireita(nodo *raiz){
    if(raiz==nullptr)
        return nullptr;
    if(raiz->esq==nullptr&&raiz->dir==nullptr)
        return raiz;
    if(raiz->esq !=nullptr)
        return extremoDireita(raiz->esq);
    else
        return extremoDireita(raiz->dir);
}

nodo *Arvore::extremoEsquerda(nodo *raiz){
    if(raiz==nullptr)
        return nullptr;
    if(raiz->esq==nullptr&&raiz->dir==nullptr)
        return raiz;
    if(raiz->esq!=nullptr)
        return extremoEsquerda(raiz->esq);
    else
        return extremoEsquerda(raiz->dir);
}

int main(){
    Arvore tree;
    tree.raiz=tree.inserir(tree.raiz, 10);
    tree.raiz=tree.inserir(tree.raiz, 5);
    tree.raiz=tree.inserir(tree.raiz, 15);
    tree.raiz=tree.inserir(tree.raiz, 2);
    tree.raiz=tree.inserir(tree.raiz, 7);

    std::cout << "Em ordem:\n";
    tree.emOrdem(tree.raiz);

    nodo* esquerda = tree.extremoEsquerda(tree.raiz);
    if (esquerda)
        std::cout << "\nFolha mais à esquerda: " << esquerda->info << std::endl;

    nodo* direita = tree.extremoDireita(tree.raiz);
    if (direita)
        std::cout << "Folha mais à direita: " << direita->info << std::endl;

    return 0;
}