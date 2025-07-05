// Implemente uma função em C++ que receba um ponteiro para a raiz de 
// uma árvore binária de pesquisa. A função deve retornar qual das 
// subárvores (esquerda ou direita) possui a maior soma dos valores das
// folhas, além de informar essa soma.

#include<iostream>
#include<string>

struct nodo {
    int info;
    nodo *esq, *dir;
};

class Arvore {
public:
    nodo *raiz;
    Arvore();
    nodo *inserir(nodo *raiz, int n);
    nodo *remover(nodo *raiz, int n);
    void em_ordem(nodo *raiz);
    nodo *substituir(nodo *raiz, nodo* sucessor);
    int somarFolhas(nodo *raiz);
    int compararValoresFolha(nodo *raiz);
    void mostrarFolhas(nodo *raiz);

};

Arvore::Arvore() {
    raiz=nullptr;
}

nodo *Arvore::inserir(nodo* raiz, int n){
    if(raiz==nullptr){
        raiz = new nodo();
        raiz->info = n;
        raiz->esq=nullptr;
        raiz->dir=nullptr;
        return raiz;
    }
    if(n<raiz->info){
        raiz->esq = inserir(raiz->esq, n);
    }
    else if(n>raiz->info){
        raiz->dir = inserir(raiz->dir, n);
    }
    else{
        std::cout<<"Valor igual";
        return raiz;
    }
    return raiz;
}

nodo *Arvore::remover(nodo *raiz, int n){
    nodo *aux;
    if(raiz==nullptr){
        std::cout<<"nao é possivel remover";
        return raiz;
    }
    if(n<raiz->info){
        raiz->esq = remover(raiz->esq, n);
    }
    else if(n>raiz->info){
        raiz->dir = remover(raiz->dir, n);
    }
    else{
        if(raiz->esq == nullptr){
            aux = raiz;
            raiz=raiz->dir;
            delete aux;
            return raiz;
        }
        else if(raiz->dir==nullptr){
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

nodo *Arvore::substituir(nodo *raiz, nodo *sucessor){
    nodo *aux;
    if(sucessor->esq !=nullptr){
        sucessor->esq = substituir(raiz, sucessor->esq);
    }
    else{
        raiz->info = sucessor->info;
        aux=sucessor;
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
    std::cout<< raiz->info << " ";
    em_ordem(raiz->dir);
}

int Arvore::somarFolhas(nodo *raiz){
    if(raiz==nullptr){
        return 0;
    }
    if(raiz->esq==nullptr&&raiz->dir==nullptr){
        return raiz->info;
    }
    return somarFolhas(raiz->esq) + somarFolhas(raiz->dir);
}

int Arvore::compararValoresFolha(nodo *raiz){
    if(raiz==nullptr){
        return 0;
    }
    int e = somarFolhas(raiz->esq);
    int d = somarFolhas(raiz->dir);

    std::cout << "\nSoma das folhas da subárvore esquerda: " << e << std::endl;
    std::cout << "Soma das folhas da subárvore direita: " << d << std::endl;

    if(e>d){
        std::cout<< e << " - esqueda maior"<<std::endl;
        return e;
    }
    else if(e<d){
        std::cout<< d << " - direita maior"<<std::endl;
        return d;
    }
    else{
        std::cout<< d << " - valores iguais"<<std::endl;
        return e;
    }
}

void Arvore::mostrarFolhas(nodo *raiz) {
    if (raiz == nullptr) return;
    if (raiz->esq == nullptr && raiz->dir == nullptr) {
        std::cout << raiz->info << " ";
    }
    mostrarFolhas(raiz->esq);
    mostrarFolhas(raiz->dir);
}

int main(){
    Arvore a;
    a.raiz = a.inserir(a.raiz, 10);
    a.raiz = a.inserir(a.raiz, 5);
    a.raiz = a.inserir(a.raiz, 3);
    a.raiz = a.inserir(a.raiz, 7);
    a.raiz = a.inserir(a.raiz, 15);
    a.raiz = a.inserir(a.raiz, 12);
    a.raiz = a.inserir(a.raiz, 20);
    a.raiz = a.inserir(a.raiz, 25);
    a.raiz = a.inserir(a.raiz, 505);
    a.raiz = a.inserir(a.raiz, 16);

    std::cout << "Folhas da subárvore esquerda: ";
    a.mostrarFolhas(a.raiz->esq);
    std::cout << "\nFolhas da subárvore direita: ";
    a.mostrarFolhas(a.raiz->dir);

    std::cout << "\n\nComparando somas das folhas das subárvores:\n";
    a.compararValoresFolha(a.raiz);

    return 0;
}
