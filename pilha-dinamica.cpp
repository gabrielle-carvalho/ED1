#include <iostream>
// using namespace std; permite usar cout, cin, endl sem escrever std:: antes

struct Nodo { // definição da estrutura Nodo
    int info;      // valor armazenado no nó
    Nodo* prox;    // ponteiro para o próximo nó
};

class PilhaD{

private:
    Nodo *topo; // Ponteiro para o topo da pilha

public:
    PilhaD();
    void empilhar(int n);
    int desempilhar();
    void listar();
};

PilhaD::PilhaD(){
    topo=nullptr; // inicializa o topo da pilha como nulo
}

    void PilhaD::empilhar(int n){ // empilha um valor na pilha
        Nodo *novo=new Nodo();// Cria um novo nó dinamicamente
        novo->info=n;  // Atribui o valor ao nó //nao pode fazer isso(se topo esta nulo)!!
        if(topo == nullptr){
            nodo->prox=nullptr; //primeiro elemento, o endereco de prox é null
        }
        else{
            novo->prox=topo; //indica o endereco do prox elemnto da fila
        }
        topo=novo;
    }

    int PilhaD::desempilhar(){
        if(topo!=nullptr){ // while tava esvaziand
            Nodo *aux=topo; // Guarda o topo atual da pilha
            topo=topo->prox; //topo agora é o prx endereco (no)
            int n = aux->info; // Armazena o valor desempilhado
            delete aux;  // Libera a memória do nó desempilhado
            return n;
        }
        else{
            cout<<"Pilha esta vazia"<<std::endl;
            return -1;
        }
    }

    void PilhaD::listar(){
        Nodo *aux=topo; // Começa no topo da pilha
        if(aux !=nullptr){
            cout<<aux->info<<endl; // Imprime o valor do nó
            aux=aux->prox; //vai para prx nó
        }
    }

}
int main(){
    PilhaD pilha;//instancia do objeto da classe pilha
    pilha.empilhar(4);
    pilha.empilhar(7);
    pilha.listar();
    pilha.desempilhar();
    pilha.listar();

    int n = pilha.desempilhar();
    cout << "Valor desempilhado: " << n << endl;
    return 0;
}
