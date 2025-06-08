/* 2. Escreva uma função, em C, que receba uma lista simplesmente encadeada, e
retorne uma lista ordenada (crescente) sem alocar espaços para novos
elementos da lista.*/
#include <iostream>
struct Nodo {
    int info;
    Nodo *prox;
};
class ListaSimples {
private:
    Nodo *inicio;

public:
    ListaSimples() {
        inicio = nullptr;
    }

    void inserirFim(int n) {
        Nodo *novo = new Nodo();
        novo->info = n;
        novo->prox = nullptr;

        if (inicio == nullptr) {
            inicio = novo;
        } else {
            Nodo *aux = inicio;
            while (aux->prox != nullptr) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }

    void listar() {
        Nodo *aux = inicio;
        while (aux != nullptr) {
            std::cout << aux->info << " ";
            aux = aux->prox;
        }
        std::cout << std::endl;
    }

    void ordenar(){
        if(inicio==nullptr || inicio->prox==nullptr){
            std::cout<<"Lista vazia ou com apenas um elemento"<<std::endl;
            return;
        }
        Nodo *novaLista=nullptr; 

        while(inicio!=nullptr){
            Nodo *aux=inicio;
            inicio=inicio->prox;
            if(novaLista==nullptr || aux->info < novaLista->info){
                aux->prox=novaLista;
                novaLista=aux;
            }
            else{
                Nodo *ant = novaLista;
                Nodo *atual = novaLista->prox;
            while((atual!=nullptr)&&(aux->info < atual->info)){
                ant=atual;
                atual=atual->prox;
            }
            aux->prox=atual;
            ant->prox=aux;
            }
        }
            inicio = novaLista;
    }
};

int main() {
    ListaSimples lista;

    // Exemplo com elementos fora de ordem
    lista.inserirFim(8);
    lista.inserirFim(3);
    lista.inserirFim(10);
    lista.inserirFim(1);

    std::cout << "Antes de ordenar: ";
    lista.listar();

    lista.ordenar();

    std::cout << "Depois de ordenar: ";
    lista.listar();

    return 0;
}