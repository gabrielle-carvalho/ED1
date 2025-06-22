#include <iostream>

struct nodo {
    int info;
    nodo *esq;
    nodo *dir;
};

class Arvore{
    public:
    nodo *raiz;
    Arvore();
    nodo *inserir(nodo *raiz, int n);
    bool imprimirAsc(nodo *raiz, int alvo);
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

bool Arvore::imprimirAsc(nodo *raiz, int alvo){
    if(raiz==nullptr){ 
        return false; 
    }
    if(raiz->info == alvo){
        return true;
    }
    if(alvo<raiz->info && imprimirAsc(raiz->esq, alvo) || (alvo>raiz->info && imprimirAsc(raiz->dir, alvo))){
        std::cout<< raiz->info << " ";
        return true;
    }
    return false;
}

int main(){
    Arvore arv;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : valores)
        arv.raiz = arv.inserir(arv.raiz, val);

    int alvo = 20;
    std::cout << "Ascendentes de " << alvo << ": ";
    arv.imprimirAsc(arv.raiz, alvo);
    std::cout << std::endl;
    
    return 0;
}
