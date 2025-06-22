#include <iostream>
struct nodo{
    int info;
    struct nodo *esq, *dir;
};

struct no {
    nodo *ptr;
    struct no * prox;
};

class Queue{
private:
    no* inicio;
    no* fim;
public:
    Queue() {
        inicio = nullptr;
        fim = nullptr;
    }

    void inserir(nodo *p) {
        no* novo = new no();
        novo->ptr = p; //ptr aponta pra arvore
        novo->prox = nullptr;

        if (inicio == nullptr) { // qnd a fila ta vazia
            inicio = novo;
            fim = novo;
        } 
        else {
            fim->prox = novo; // último nó existente aponta pro novo
            fim = novo; // fim agora é o novo nó
        }
    }

    nodo* remover() {
        if (inicio == nullptr) {
            std::cout << "Fila vazia!" << std::endl;
            return nullptr;
        }

        no* temp = inicio; // guarda o primeiro nó da fila
        nodo *valor = temp->ptr;  // pega o ponteiro para o nodo da árvore

        inicio = inicio->prox; // o segundo da fila vira o primeiro
      
        if (inicio == nullptr) {
            fim = nullptr; // ficou vazia dnv
        }

        delete temp; // apaga o nó antigo
        return valor;
    }

    bool vazia() {
        return inicio == nullptr;
    }

    no* getInicio() {
        return inicio;
    }

};

class Arvore{
    public:
    nodo *raiz;
    Arvore();
    nodo *inserir(nodo *raiz, int n);
    nodo* retirar(nodo *raiz, int n);
    nodo* substitui(nodo *raiz, nodo *sucessor);
    int altura(nodo *raiz);
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

nodo *Arvore::retirar(nodo *raiz, int n){
    nodo *ret = nullptr;
    if(raiz == nullptr){
        return nullptr;
    }
    if(raiz->info < n){
        raiz->dir = retirar(raiz->dir, n);
    }
    else if(raiz->info > n){
        raiz->esq = retirar(raiz->esq, n);
    }
    else{
        if (raiz->esq == nullptr) {
            nodo* temp = raiz->dir;
            delete raiz;
            return temp;
        }
        else if (raiz->dir == nullptr) {
            nodo* temp = raiz->esq;
            delete raiz;
            return temp;
        }
        else {
            nodo* sucessor = raiz->dir;
            while (sucessor->esq != nullptr) {
                sucessor = sucessor->esq;
            }
            raiz->info = sucessor->info; // valor do sucessor para o nó atual

            raiz->dir = retirar(raiz->dir, sucessor->info); // remove o sucessor
        }
    }
    return raiz;
}

nodo *Arvore::substitui(nodo *raiz, nodo *sucessor){
    nodo *ret;
    if(sucessor->esq==nullptr){
        raiz->info=sucessor->info;
        ret=sucessor;
        sucessor=sucessor->dir;
        delete(ret);
    }
    else{
        sucessor->esq=substitui(raiz, sucessor->esq);
    }
    return sucessor;
}

int Arvore::altura(nodo *raiz){
    if(raiz==nullptr)
        return -1;
    if(raiz->dir==nullptr && raiz->esq==nullptr)
        return 0;
    int e = altura(raiz->esq);
    int d = altura(raiz->dir);
    if(e>d)
        return e+1;
    else
        return d+1;
}

void largura (nodo *raiz){
    Queue f;
    if(raiz==nullptr) return;
    f.inserir(raiz);
    while(f.getInicio()!=nullptr){
        raiz = f.getInicio()->ptr;
        std::cout<< raiz->info << " ";
        if(raiz->esq != nullptr){
            f.inserir(raiz->esq);
        }
        if(raiz-> dir != nullptr){
            f.inserir(raiz->dir);
        }
        f.remover();
    }
}

int main(){
    Arvore a;
    a.raiz = a.inserir(a.raiz, 10);
    a.raiz = a.inserir(a.raiz, 5);
    a.raiz = a.inserir(a.raiz, 15);
    a.raiz = a.inserir(a.raiz, 3);
    a.raiz = a.inserir(a.raiz, 7);
    a.raiz = a.inserir(a.raiz, 8);

    std::cout << "Largura: ";
    largura(a.raiz);
    std::cout << std::endl;
}