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
    // faça POS ORDEM!
    // faca PRE ORDEM!
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

void inserirInterativo(Nodo *raiz, int n){
    Nodo *atual, *pai;
    if(raiz == nullptr){
        raiz=new nodo();
        if(raiz==nullptr) exit(1); //nao conseguiu criar a area e nao ha mais nada a fazer
        raiz->info=n;
        raiz->esq=nullptr;
        raiz->dir=nullptr;
        return raiz;
    }
    atual=raiz;
    while(atual!=nullptr){
        pai=atual;
        if(n>atual->info){
            atual = atual->dir;
        }
        else if(n<atual->info){
            atual = atual->esq;
        }
        else{
            std::cout<<"Número igual a algum que esta na lista. RETORNANDO"<<std::endl;
            return;
        }
        atual=new nodo();
        if(!atual){
            exit(1);
        }
        atual->info=n;
        atual->esq=nullptr;
        atual->dir=nullptr;
        if(n>pai->info){
            pai->dir=atual;
        }
        else{
            pai->esq=atual;
        }
    }

}

void emOrdem(nodo *raiz){
    if(raiz==nullptr) return;
    emOrdem(raiz->esq); // vai ate o ultimo elemento existente na esquerda e coloca na fila
    std::cout<< raiz->info <<std::endl; // qunado nao ha mais elementos a esquerda, comeca a printar
    emOrdem(raiz->dir); //chama os valores pela ireita ate o fim, recursividade dnv
}

int main(){
    Arvore tree;
    tree.raiz=inserir(tree.raiz, 10); // pesquisar porque é chamdo assim, passando tree.raiz
}
