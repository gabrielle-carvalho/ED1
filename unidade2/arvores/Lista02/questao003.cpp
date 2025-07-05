//  Escreva uma função  recursiva, em C++, para gerar uma pilha contendo os nós ascendentes de 
// um  determinado  nó  de  uma  árvore  binária  de  pesquisa,  de  tal  forma  que  no  topo  da  pilha 
// encontraremos sempre o maior valor dos nós ascendentes. 

#include <iostream>

struct no {
    int info;
    no *prox;
};
struct nodo {
    int info;
    nodo *esq;
    nodo *dir;
};

class Stack{
    private:
        no* topo;
    public:
        Stack();
        void empilhar(int n);
        int desempilhar();
};

Stack::Stack() {
    topo = nullptr;
}

void Stack::empilhar(int n) {
    no *novo = new no();
    novo->info = n;

    if (topo == nullptr) { // qnd a fila ta vazia
        novo->prox = nullptr;
    } 
    else {
        novo->prox=topo;
    }
    topo=novo;
}

int Stack::desempilhar() {
    if (topo != nullptr) {
        no *aux = topo;
        topo=topo->prox;
        int n = aux->info;
        delete aux;
        return n;
    }
    std::cout<<"Pilha vazia"<<std::endl;
    return -1;
}


class Arvore{
    public:
    nodo *raiz;
    Arvore();
    nodo *inserir(nodo *raiz, int n);
    bool imprimirAsc(nodo *raiz, int alvo);
    bool empilharAscendentes(nodo *raiz, int alvo, Stack &pilha);
};

Arvore :: Arvore (){
    raiz=nullptr;
}

nodo *Arvore::inserir(nodo *raiz, int n){
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

bool Arvore::empilharAscendentes(nodo *raiz, int alvo, Stack &pilha) {
    if(raiz==nullptr) 
        return 0;
    if (raiz->info == alvo)
        return 1;
    if(alvo<raiz->info){
        empilharAscendentes(raiz->esq, alvo, pilha);
        pilha.empilhar(raiz->info);
        return 1;
    }
    else if(alvo>raiz->info){
        empilharAscendentes(raiz->dir, alvo, pilha);
        pilha.empilhar(raiz->info);
        return 1;
    }
    return 0;
}

int main() {
    Arvore arv;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : valores)
        arv.raiz = arv.inserir(arv.raiz, val);

    int alvo = 20;
    std::cout << "Ascendentes de " << alvo << " empilhados: ";

    Stack pilha;
    arv.empilharAscendentes(arv.raiz, alvo, pilha);

    int v;
    while ((v = pilha.desempilhar()) != -1) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
