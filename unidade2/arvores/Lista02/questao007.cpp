#include<iostream>

struct nodo {
    int info;
    nodo *esq, *dir;
};

class Arvore {
public:
    nodo *raiz;
    Arvore();
    nodo *inserir(nodo *raiz, int n);
    nodo *retirar(nodo *raiz, int n);
    nodo substituir(nodo *raiz, nodo *sucessor);
    void em_ordem(nodo *raiz);
    nodo *listaNodos();

};

struct No {
    int info;
    No *ant, *prox;
};

class ListaDupla {
private:
    No *inicio;
    No *atual;
public:
    ListaDupla() {
        inicio = nullptr;
        atual = nullptr;
    }

    void inserir(int n) {
        No *novo = new No();
        novo->info = n;
        novo->prox=nullptr;

        if (inicio == nullptr) {
            novo->ant = nullptr;
            inicio = novo;
            atual = novo;
            return;
        }

        novo->ant = atual;
        novo->prox = atual->prox;

        if(atual->prox != nullptr){
            atual->prox->ant = novo;
        }

        atual->prox=novo;
        atual=novo;

    }

    void retirarAtual() {
        if (atual == nullptr) {
            std::cout << "Sem elementos para retirar\n";
            return;
        }

        if (atual->ant == nullptr && atual->prox==nullptr) {
            std::cout << "Único elemento retirado\n";
            delete atual;
            inicio = nullptr;
            atual = nullptr;
            return;
        } 
        No *aux = atual;
        if(aux->ant !=nullptr){
            aux->ant->prox = aux->prox;
        } else{
            inicio=aux->prox;
        }
        if(aux->prox != nullptr){
            aux->prox->ant = aux->ant;
            atual = aux->prox;  
        }
         else {
            atual=aux->ant;
         }

        delete aux;
    }

    int getAtual() {
        if (atual != nullptr) {
            return atual->info;
        } else {
            return -1;
        }
    }
};

void menu(ListaDupla &lista) {
    char opcao;
    while (true) {
        std::cout << "\nPalavra atual: " << lista.getAtual() << "\n";
        std::cout << "D: Inserir (depois da palavra atual)\n";
        std::cout << "S: Eliminar palavra atual\n";
        std::cout << "X: Sair\n";
        std::cout << "Digite sua opção: ";
        std::cin >> opcao;

        switch (opcao) {
        case 'd': case 'D': {
            int word;
            std::cout << "Insira a palavra que você quer inserir após a atual: ";
            std::cin >> word;
            lista.inserir(word);
            break;
        }
        case 's': case 'S': {
            lista.retirarAtual();
            break;
        }
        case 'x': case 'X': {
            return;
        }
        default: {
            std::cout << "Opção inválida!\n";
            break;
        }
        }
    }
}

Arvore::Arvore() {
    raiz = nullptr;
}

nodo *Arvore::inserir(nodo *raiz, int n){
    if(raiz==nullptr){
        raiz=new nodo();
        raiz->info=n;
        raiz->esq=nullptr;
        raiz->dir=nullptr;
        return raiz;
    }
    if(n<raiz->info){
        raiz->dir = inserir(raiz->dir,n);
    }
    else if(n>raiz->info){
        raiz->esq = inserir(raiz->esq, n);
    }
    else{
        std::cout<<"numero igual a um existente";
        return raiz;
    }
    return raiz;
}

nodo *Arvore::substituir(nodo *raiz, nodo *sucessor){
    nodo *aux;
    if(sucessor->esq != nullptr){
        sucessor->esq = substituir(raiz, sucessor->esq);
    }
    else{
        raiz->info = sucessor->info;
        aux = sucessor;
        sucessor = sucessor->dir;
        delete aux;
        return sucessor;
    }
    return raiz;
}

void Arvore::em_ordem(nodo *raiz){
    if(raiz==nullptr){
        return;
    }
    em_ordem(raiz->esq);
    std::coour<< raiz->info <<std::endl;
    em_ordem(raiz->dir);
}

nodo *Arvore::retirar(nodo *raiz, int n){
    nodo *aux;
    if(raiz==nullptr){
        return raiz;
    }
    if(n>raiz->info){
        raiz->dir = retirar(raiz->dir, n);
    }
    else if(n<raiz->info){
        raiz->esq = retirar(raiz->esq, n);
    }
    else {
        if(raiz->esq == nullptr){
            aux=raiz;
            raiz=raiz->dir;
            delete aux;
            return raiz;
        }
        if(raiz->dir==nullptr){
            aux=raiz;
            raiz=raiz->esq;
            delete aux;
            return raiz;
        }
        else{
            raiz->dir = substituir(raiz, raiz->dir);
        }
    }
    return raiz;
}

Arvore::listaNodos(){

}
