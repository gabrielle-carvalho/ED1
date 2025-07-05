// mplemente uma função em C++ que, dada a raiz de uma árvore binária de pesquisa, modifique a árvore de forma
//  que ambas as subárvores da raiz principal tenham mesma altura. Para isso, insira nós com valor -1 nas posições necessárias.

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
    int altura(nodo *raiz);
    void igualarAlt(nodo *raiz);
    void mostrarFolhas(nodo *raiz);
    nodo *addFolha(nodo *raiz, int atual, int alvo);

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

nodo *Arvore::addFolha(nodo *raiz, int atual, int alvo){
    if(atual==alvo){
        return raiz;
    }
    if(raiz==nullptr){
        raiz =new nodo();
        raiz->info = -1;
        raiz->esq=nullptr;
        raiz->dir=nullptr;
    }

    raiz->esq = addFolha(raiz->esq, atual + 1, alvo);
    raiz->dir = addFolha(raiz->dir, atual + 1, alvo);

    return raiz;
}

void Arvore::igualarAlt(nodo *raiz){
    if(raiz==nullptr){
        return;
    }
    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);

    if(altE>altD){
        raiz->dir = addFolha(raiz->dir, 1, altE);
    }
    else if(altE<altD){
        raiz->esq = addFolha(raiz->esq, 1, altD);
    }
    else{
        std::cout<<"Alturas já igualadas";
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



    a.igualarAlt(a.raiz);

    std::cout << "\n\nApós igualar alturas:\n";
    std::cout << "Altura esquerda: " << a.altura(a.raiz->esq) << std::endl;
    std::cout << "Altura direita: " << a.altura(a.raiz->dir) << std::endl;


    std::cout << "Folhas da subárvore esquerda: ";
    a.mostrarFolhas(a.raiz->esq);
    std::cout << "\nFolhas da subárvore direita: ";
    a.mostrarFolhas(a.raiz->dir);


    return 0;
}
