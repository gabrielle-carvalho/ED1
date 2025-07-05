#include <iostream>
#include <cstdlib> 

struct nodo{
    int info;
    struct nodo *esq, *dir;
};

class Arvore{
    public:
    nodo *raiz;
    Arvore();
    nodo *inserir(nodo *raiz, int n); // 
    void emOrdem(nodo *raiz); // esquerda | raiz | direita
    int buscar(nodo *raiz, int n);
    int altura(nodo *raiz);
    bool compararAltura(nodo *raiz1, nodo *raiz2);
};

Arvore :: Arvore (){
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
    std::cout<< "\n" << raiz->info <<std::endl; // qunado nao ha mais elementos a esquerda, comeca a printar
    emOrdem(raiz->dir); //chama os valores pela ireita ate o fim, recursividade dnv
}

int Arvore::buscar(nodo *raiz, int n){
    if(raiz==nullptr) return -1;
    if(raiz->info==n){
        return raiz->info;
    }
    if(raiz->info>n){
        return buscar(raiz->esq, n);
    }
    else{
        return buscar(raiz->dir, n);
    }
}

int Arvore::altura(nodo *raiz){
    if(raiz==nullptr){
        return -1;
    }
    else{
        int e = altura(raiz->esq);
        int d = altura(raiz->dir);
        if(e>d){
            return e+1;
        }
        else{
            return d+1;
        }
    }
}

bool Arvore::compararAltura(nodo *raiz1, nodo *raiz2){
    if(raiz1==nullptr||raiz2==nullptr){
        return 0;
    }
    int alt1 = altura(raiz1);
    int alt2 = altura(raiz2);
    if(alt1==alt2){
        return 1;
    }
    return 0;
}

int main(){
    Arvore tree;
    Arvore arv;
    tree.raiz = tree.inserir(tree.raiz, 10);
    tree.raiz = tree.inserir(tree.raiz, 5);
    tree.raiz = tree.inserir(tree.raiz, 15);
    tree.raiz = tree.inserir(tree.raiz, 19);
    tree.raiz = tree.inserir(tree.raiz, 50);
    tree.raiz = tree.inserir(tree.raiz, 1);

    arv.raiz = arv.inserir(arv.raiz, 100);
    arv.raiz = arv.inserir(arv.raiz, 50);
    arv.raiz = arv.inserir(arv.raiz, 105);
    arv.raiz = arv.inserir(arv.raiz, 190);
    arv.raiz = arv.inserir(arv.raiz, 500);
    arv.raiz = arv.inserir(arv.raiz, 10);
    arv.raiz = arv.inserir(arv.raiz, 12);
    arv.raiz = arv.inserir(arv.raiz, 50000);
    arv.raiz = arv.inserir(arv.raiz, 1000);
    arv.raiz = arv.inserir(arv.raiz, 1200);

    std::cout << "Árvore 1 (em ordem): ";
    tree.emOrdem(tree.raiz);
    std::cout << std::endl;

    std::cout << "Árvore 2 (em ordem): ";
    arv.emOrdem(arv.raiz);
    std::cout << std::endl;

    int valor = 15;
    int resultado = tree.buscar(tree.raiz, valor);
    if (resultado != -1)
        std::cout << "Valor " << valor << " encontrado na árvore 1.\n";
    else
        std::cout << "Valor " << valor << " NÃO encontrado na árvore 1.\n";

    bool iguais = tree.compararAltura(tree.raiz, arv.raiz);
    std::cout << "As duas árvores têm " << (iguais ? "a mesma altura" : "altura diferente") << ".\n";


    return 0;
}
