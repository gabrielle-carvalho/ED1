#include <iostream>
using namespace std;

// Definição do nó
struct Nodo {
    int info;
    Nodo* prox;
};

// Definição da classe da lista encadeada
class listaS {
private:
    Nodo* inicio;  // Ponteiro para o início da lista

public:
    // Construtor
    listaS() : inicio(nullptr) {}

    // Destruidor para liberar a memória
    ~listaS() {
        Nodo* temp;
        while (inicio != nullptr) {
            temp = inicio;
            inicio = inicio->prox;
            delete temp;
        }
    }

    // Função para adicionar um nó no final da lista
    void adicionar(int valor) {
        Nodo* novo = new Nodo;
        novo->info = valor;
        novo->prox = nullptr;

        if (inicio == nullptr) {
            inicio = novo;
        } else {
            Nodo* temp = inicio;
            while (temp->prox != nullptr) {
                temp = temp->prox;
            }
            temp->prox = novo;
        }
    }

    // Função para exibir a lista
    void exibir() const {
        Nodo* temp = inicio;
        while (temp != nullptr) {
            cout << temp->info << " ";
            temp = temp->prox;
        }
        cout << endl;
    }

    // Função para ordenar a lista
    void ordenar() {
        Nodo *novalista, *ant, *atual, *aux;
        novalista = nullptr;
        if (inicio == nullptr) {
            return;  // Lista vazia, não precisa ordenar
        }
        while (inicio != nullptr) {
            aux = inicio;
            inicio = inicio->prox;
            if (novalista == nullptr || aux->info <= novalista->info) {
                aux->prox = novalista;
                novalista = aux;
            } else {
                atual = novalista;
                while (atual->prox != nullptr && atual->prox->info < aux->info) {
                    atual = atual->prox;
                }
                aux->prox = atual->prox;
                atual->prox = aux;
            }
        }
        inicio = novalista;
    }

    // Função para remover os elementos repetidos
    void retirarRepetidos() {
        Nodo *novalista, *aux, *atual, *fim;
        if (inicio == nullptr) {
            cout << "Lista vazia" << endl;
            return;
        }
        novalista = nullptr;
        while (inicio != nullptr) {
            aux = inicio;
            inicio = inicio->prox;
            if (novalista == nullptr) {
                novalista = aux;
                novalista->prox = nullptr;
            } else {
                // Verifica se o elemento já existe na nova lista
                atual = novalista;
                while (atual != nullptr && atual->info != aux->info) {
                    atual = atual->prox;
                }
                if (atual == nullptr) {  // Se não encontrar o valor, adiciona à nova lista
                    fim = novalista;
                    while (fim->prox != nullptr) {  // Vai até o último nó
                        fim = fim->prox;
                    }
                    fim->prox = aux;
                    aux->prox = nullptr;
                } else {
                    delete aux;  // Se o valor já existe, deleta o nó repetido
                }
            }
        }
        inicio = novalista;
    }
};

int main() {
    listaS lista;

    // Adicionando elementos à lista
    lista.adicionar(3);
    lista.adicionar(5);
    lista.adicionar(3);
    lista.adicionar(7);
    lista.adicionar(5);
    lista.adicionar(2);

    cout << "Lista original: ";
    lista.exibir();

    // Ordenando a lista
    lista.ordenar();
    cout << "Lista ordenada: ";
    lista.exibir();

    // Remover elementos repetidos
    lista.retirarRepetidos();
    cout << "Lista após remoção de repetidos: ";
    lista.exibir();

    return 0;
}
