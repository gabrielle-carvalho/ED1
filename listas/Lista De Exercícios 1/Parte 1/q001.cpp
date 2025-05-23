/* 1. Escreva funções, em C, que recebam uma lista simplesmente encadeada
ordenada, e realizem as seguintes operações:
a. retirar todos os elementos ímpares que são primos, e, gerar uma
outra lista contendo apenas os elementos retirados da lista inicial,
em ordem decrescente;

b. retirar todos os elementos pares da lista inicial.
OBS.: utilize o tipo Nodo criado em aula. */
#include <iostream>
#include <cmath>

struct Nodo {
    int info;
    Nodo *prox;
};

class ListaSimples {
private:
    Nodo *inicio;

    bool ehPrimo(int n){
        if(n<=1){
            return false;
        }
        for(int i=2; i<=sqrt(n); ++i){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }


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
        }
        else{
            Nodo *aux = inicio;
            while(aux->prox != nullptr){
                aux = aux->prox;
            }
            aux->prox=novo;
        }
    }

    void inserirDestino(int n){
        Nodo * novo = new Nodo();
        novo->info=n;
        novo->prox=inicio;
        inicio=novo;
    }

    void listar (){
        Nodo *aux = inicio;
        while(aux!=nullptr){
            std::cout<<aux->info << " ";
            aux = aux->prox;
        }
        std::cout << "\n";
    }

    void retirarImparPrimo(ListaSimples &destino){
        Nodo *atual = inicio;
        Nodo *ant = nullptr;
        while(atual!=nullptr){
            if ((atual->info % 2 != 0) && (ehPrimo(atual->info))){
                if(ant == nullptr){ //for o primeiro
                    inicio=atual->prox;
                }
                else{
                    ant->prox=atual->prox; //encadea o ant com prox, pulando atual
                }
                destino.inserirDestino(atual->info); //add esse num a lista destno
                Nodo *removido = atual;
                atual=atual->prox;
                delete removido;
            }
            else{
                ant=atual;
                atual=atual->prox;
            }
        }
    }

    void retirarPares(){
        Nodo *atual = inicio;
        Nodo *ant = nullptr; //ponteiro local que ajuda a percorrer
        while(atual != nullptr){
            if(atual->info %2 == 0){
                if(ant==nullptr){
                    inicio=atual->prox;
                }
                else{
                    ant->prox = atual->prox;
                }
                Nodo *removido =atual;
                atual=atual->prox;
                delete removido;
            }
            else{
                ant=atual;
                atual=atual->prox;
            }
        }
    }
};

int main() {
    ListaSimples listaOriginal;
    ListaSimples listaPrimos;

    int valores[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for (int v : valores)
        listaOriginal.inserirFim(v);

    std::cout << "Lista original:\n";
    listaOriginal.listar();

    listaOriginal.retirarImparPrimo(listaPrimos);

    std::cout << "\nApós retirar ímpares primos:\n";
    std::cout << "Lista original: ";
    listaOriginal.listar();

    std::cout << "Lista de primos ímpares (decrescente): ";
    listaPrimos.listar();

    listaOriginal.retirarPares();
    std::cout << "\nApós retirar pares:\n";
    listaOriginal.listar();

    return 0;
}
