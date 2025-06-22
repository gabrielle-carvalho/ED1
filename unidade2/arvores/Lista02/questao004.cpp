// Escreva uma função, em C, para imprimir a(s) folha(s) de maior nível, e a(s) folha(s) de menor 
// nível, com os seus respectivos níveis, de uma árvore binária.

#include<iostream>

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
        void folhasExtremas();
    private:
        int encontrarMinNivel(nodo *raiz, int nivel);
        int encontrarMaxNivel(nodo *raiz, int nivel);
        void imprimirFolhas(nodo *raiz, int nivel, int alvoMin, int alvoMax);
};

Arvore :: Arvore (){
    raiz=nullptr;
}

nodo *Arvore::inserir(nodo *raiz, int n){
    if (raiz==nullptr){
        raiz = new nodo{n, nullptr, nullptr};
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

int Arvore::encontrarMinNivel(nodo *raiz, int nivel){
    if(raiz==nullptr) 
        return 9000;
    if(raiz->esq==nullptr&&raiz->dir==nullptr)
        return nivel;
    int esq = encontrarMinNivel(raiz->esq, nivel + 1);
    int dir = encontrarMinNivel(raiz->dir, nivel + 1);
    return std::min(esq, dir);
}

int Arvore::encontrarMaxNivel(nodo *raiz, int nivel){
    if(raiz==nullptr) 
        return -1;
    if(raiz->esq==nullptr&&raiz->dir==nullptr)
        return nivel;
    int esq = encontrarMaxNivel(raiz->esq, nivel + 1);
    int dir = encontrarMaxNivel(raiz->dir, nivel + 1);
    return std::max(esq, dir);
}

void Arvore::imprimirFolhas(nodo *raiz, int nivel, int alvoMin, int alvoMax){
    if (raiz == nullptr)
        return;
    if (raiz->esq == nullptr && raiz->dir == nullptr){
        if (nivel == alvoMin)
            std::cout << raiz->info << "\n";
        else if (nivel == alvoMax)
            std::cout << raiz->info << "\n";
    }
    imprimirFolhas(raiz->esq, nivel + 1, alvoMin, alvoMax);
    imprimirFolhas(raiz->dir, nivel + 1, alvoMin, alvoMax);
}


void Arvore::folhasExtremas(){
    int minNivel = encontrarMinNivel(raiz,0);
    int maxNivel = encontrarMaxNivel(raiz,0);
    std::cout << "Folhas do maior nível (" << maxNivel << "):\n";
    imprimirFolhas(raiz, 0, -1, maxNivel);
    std::cout << "Folhas do menor nível (" << minNivel << "):\n";
    imprimirFolhas(raiz, 0, minNivel, -1);
}

int main() {
    Arvore arv;
    int valores[] = {50, 30, 70, 20, 40, 10, 25, 60, 80};
    for (int v : valores)
        arv.raiz = arv.inserir(arv.raiz, v);

    arv.folhasExtremas();
    return 0;
}


