#include <iostream>
struct Nodo {
    int info;
    Nodo* prox;
};

class FilaD {
private:
    Nodo* inicio;
    Nodo* fim;

public:
    FilaD() {
        inicio = nullptr;
        fim = nullptr;
    }

    void inserir(int n) {
        Nodo* novo = new Nodo();
        novo->info = n;
        novo->prox = nullptr;

        if (inicio == nullptr) { // qnd a fila ta vazia
            inicio = novo;
            fim = novo;
        } 
        else {
            fim->prox = novo; // último nó existente aponta pro novo
            fim = novo; // fim agora é o novo nó
        }
    }

    int remover() {
        if (inicio == nullptr) {
            std::cout << "Fila vazia!" << std::endl;
            return -1;
        }

        Nodo* temp = inicio; // guarda o primeiro nó
        int valor = temp->info; // pega o valor dele

        inicio = inicio->prox; // o segundo da fila vira o primeiro
      
        if (inicio == nullptr) {
            fim = nullptr; // ficou vazia dnv
        }

        delete temp; // apaga o nó antigo
        return valor;
    }

    void listar() {
        Nodo* aux = inicio;
        while (aux != nullptr) {
            std::cout << aux->info << " ";
            aux = aux->prox;
        }
        std::cout << std::endl;
    }
};

int main() {
    FilaD fila;

    fila.inserir(10);
    fila.inserir(20);
    fila.inserir(30);
    fila.listar();

    std::cout << "Removido: " << fila.remover() << std::endl;
    fila.listar();

    return 0;
}
