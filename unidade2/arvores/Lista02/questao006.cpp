// 6.  Considere  uma    árvore    binária    de    pesquisa    que    contém    em    cada    nó  as    seguintes 
// informações relacionadas aos alunos de um determinado curso: o código (inteiro) do aluno e a 
// média no curso. Escreva uma função, em C, para retirar as folhas da árvore e gerar uma pilha 
// contendo  apenas  as  folhas  (sem  alocar  nenhum  novo  endereço),  de  tal  forma  que no  topo  da 
// pilha encontraremos sempre o maior código do aluno.

#include <iostream>

struct no {
    int codigo;
    float media;
    no *esq, *dir;
};

struct Nodo {
    int info;      
    Nodo* prox;   
};

class PilhaD{

private:
    Nodo *topo; // Ponteiro para o topo da pilha

public:
    PilhaD();
    void empilhar(int n);
    void listar();
};

class Arvore {
public:
    no *raiz;
    Arvore();
    no *inserir(no * raiz, int cod, float med);
    no *retirar(no *raiz, int n);
    void pilhaFolhas();
};

Arvore::Arvore() {
    raiz = nullptr;
}

PilhaD::PilhaD(){
    topo=nullptr;
}

no *Arvore::inserir(no *raiz, int cod, float med){
    if(raiz==nullptr){
        raiz=new no();
        raiz->codigo=cod;
        raiz->media=med;
        raiz->esq=nullptr;
        raiz->dir=nullptr;
        return raiz;
    }

    if(cod > raiz->codigo){
        raiz->dir = inserir (raiz->dir, cod, med);
    }
    else if(cod<raiz->codigo){
        raiz->esq = inserir(raiz->esq, cod, med);
    }
    else{
        std::cout<<"Valor repetido";
        return raiz;
    }
    return raiz;
}


void retirarEempilharFolhas(no *&raiz, PilhaD &P) {
    if (raiz == nullptr) return;


    if (raiz->esq == nullptr && raiz->dir == nullptr) {
        std::cout << "Empilhando e removendo folha: " << raiz->codigo << std::endl;
        P.empilhar(raiz->codigo);
        delete raiz;
        raiz = nullptr;
        return;
    }

    retirarEempilharFolhas(raiz->esq, P);
    retirarEempilharFolhas(raiz->dir, P);

}

void Arvore::pilhaFolhas(){
    PilhaD P;
    retirarEempilharFolhas(raiz, P);
    std::cout << "Pilha com as folhas: ";
    P.listar();
}

void PilhaD::empilhar(int n){ // empilha um valor na pilha
    Nodo *novo=new Nodo();// Cria um novo nó dinamicamente
    novo->info=n;  // Atribui o valor ao nó //nao pode fazer isso(se topo esta nulo)!!
    if(topo == nullptr){
        novo->prox=nullptr; //primeiro elemento, o endereco de prox é null
    }
    else{
        novo->prox=topo; //indica o endereco do prox elemnto da fila
    }
    topo=novo;
}

void PilhaD::listar(){
    Nodo *aux = topo;
    while(aux != nullptr){
        std::cout << aux->info << " ";
        aux = aux->prox;
    }
    std::cout << std::endl;
}


int main() {
    Arvore arv;
    arv.raiz = arv.inserir(arv.raiz, 10, 7.5);
    arv.raiz = arv.inserir(arv.raiz, 5, 8.0);
    arv.raiz = arv.inserir(arv.raiz, 3, 9.0);
    arv.raiz = arv.inserir(arv.raiz, 7, 6.5);
    arv.raiz = arv.inserir(arv.raiz, 15, 8.5);
    arv.raiz = arv.inserir(arv.raiz, 12, 5.0);
    arv.raiz = arv.inserir(arv.raiz, 18, 7.0);

    std::cout << "Chamando pilhaFolhas()\n";
    arv.pilhaFolhas(); 

    return 0;
}

