#include <iostream>

class PilhaD{
    private:
        Nodo *topo;
    public:
        PilhaD();

    void empilhar(int n);
    int empilhar();
    void listar();


    PilhaD::PilhaD(){
        topo=nullptr;
    }
    novo->info=3; //novo apontando pro campo info recebe 3

    void PilhaD::empilhar(int n){
        Nodo *novo;
        novo=new Nodo();
        novo->info=n; //nao pode fazer isso(se topo esta nulo)!!
        if(topo == nullptr){
            nodo->prox=nullptr; //primeiro elemento, o endereco de prox é null
        }
        else{
            novo->prox=topo; //indica o endereco do prox elemnto da fila
        }
        topo=novo;
    }

    int PilhaD::desempilhar(){
        Nodo *aux;
        if(topo!=nullptr){
            aux=topo;
            topo=topo->prox; //topo agora é o endereco abaixo
            int n = aux->info;
            delete aux;
            return n;
        }
        else{
            cout<<"Pilha esta vazia";
            return -1;
        }
    }

}
int main(){
    PilhaD pilha;//instancia do objeto da classe pilha
    pilha.empilhar(4);
    pilha.empilhar(7);
    pilha.desempilhar();
    int n = pilha.desempilhar();
}


/*
struct Nodo{
    int info;
    struct Nodo *prox;
};

Nodo *novo;
novo=new Nodo();
*/

// jeito menos usual:
// (*novo).info=3
