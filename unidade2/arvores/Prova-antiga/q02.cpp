// Faça uma função em C que receba como parâmetro o ponteiro para a raiz de uma árvore
// binária de pesquisa já criada. A função deverá igualar o número de folhas das sub-
// árvores da raiz principal.

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
    int contarFolhas(nodo *raiz);
    std::pair<std::string, int>  qtdLadoFolhas(nodo *raiz);
    void mostrarFolhas(nodo *raiz);
    nodo *removerFolha(nodo *raiz);
    void igualarFolhas();

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

int Arvore::contarFolhas(nodo *raiz){
    if(raiz==nullptr){
        return 0;
    }
    if(raiz->esq==nullptr&&raiz->dir==nullptr){
        return 1;
    }
    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

std::pair<std::string, int> Arvore::qtdLadoFolhas(nodo *raiz){
    if(raiz==nullptr){
        return {"nenhum", 0}; 
        
    }
    int e = contarFolhas(raiz->esq);
    int d = contarFolhas(raiz->dir);

    if(e>d){
        return {"esquerda", e}; 
    }
    else if(e<d){
        return {"direita", d}; 
    }
    else{
        return {"igual", e};
    }

}

nodo *Arvore::removerFolha(nodo *raiz){
    if(raiz==nullptr) 
        return nullptr;
    if(raiz->esq==nullptr&&raiz->dir==nullptr){
        delete raiz;
        return nullptr;
    }
    if(raiz->esq!=nullptr){
        raiz->esq = removerFolha(raiz->esq);
    }
    else if(raiz->dir!=nullptr){
        raiz->dir =  removerFolha(raiz->dir);
    }
    return raiz;
}

void Arvore::igualarFolhas(){
    if(raiz==nullptr){
        return;
    }
    int qtdE = contarFolhas(raiz->esq);
    int qtdD = contarFolhas(raiz->dir);

    while (qtdE!=qtdD) {
        if(qtdE>qtdD){
            raiz->esq = removerFolha(raiz->esq);
        }
        else{
            raiz->dir = removerFolha(raiz->dir);
        }

        qtdD=contarFolhas(raiz->dir);
        qtdE=contarFolhas(raiz->esq);
    }
    std::cout << "\nFolhas igualadas: esquerda = " << qtdE << ", direita = " << qtdD << "\n";    
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

    a.igualarFolhas();

    std::cout << "\nApós igualar:\n";
    std::cout << "Folhas da subárvore esquerda: ";
    a.mostrarFolhas(a.raiz->esq);
    std::cout << "\nFolhas da subárvore direita: ";
    a.mostrarFolhas(a.raiz->dir);
    std::cout << std::endl;

    return 0;
}
