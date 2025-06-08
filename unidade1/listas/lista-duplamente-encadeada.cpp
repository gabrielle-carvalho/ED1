#include <iostream>

struct Nodo {
    int info;
    Nodo *ant, *prox;
};

class ListaDupla {
private:
    Nodo *inicio;
    Nodo *atual;
public:
    ListaDupla() {
        inicio = nullptr;
        atual = nullptr;
    }

    void inserir(int n) {
        Nodo *novo = new Nodo();
        novo->info = n;
        novo->prox=nullptr;

        if (inicio == nullptr) {
            novo->ant = nullptr;
            inicio = novo;
            atual = novo;
            return;
        }

        novo->ant = atual;
        novo->prox = atual->prox;

        if(atual->prox != nullptr){
            atual->prox->ant = novo;
        }

        atual->prox=novo;
        atual=novo;

    }

    void retirarAtual() {
        if (atual == nullptr) {
            std::cout << "Sem elementos para retirar\n";
            return;
        }

        if (atual->ant == nullptr && atual->prox==nullptr) {
            std::cout << "Único elemento retirado\n";
            delete atual;
            inicio = nullptr;
            atual = nullptr;
            return;
        } 
        Nodo *aux = atual;
        if(aux->ant !=nullptr){
            aux->ant->prox = aux->prox;
        } else{
            inicio=aux->prox;
        }
        if(aux->prox != nullptr){
            aux->prox->ant = aux->ant;
            atual = aux->prox;  
        }
         else {
            atual=aux->ant;
         }

        delete aux;
    }

    int getAtual() {
        if (atual != nullptr) {
            return atual->info;
        } else {
            return -1;
        }
    }
};

void menu(ListaDupla &lista) {
    char opcao;
    while (true) {
        std::cout << "\nPalavra atual: " << lista.getAtual() << "\n";
        std::cout << "D: Inserir (depois da palavra atual)\n";
        std::cout << "S: Eliminar palavra atual\n";
        std::cout << "X: Sair\n";
        std::cout << "Digite sua opção: ";
        std::cin >> opcao;

        switch (opcao) {
        case 'd': case 'D': {
            int word;
            std::cout << "Insira a palavra que você quer inserir após a atual: ";
            std::cin >> word;
            lista.inserir(word);
            break;
        }
        case 's': case 'S': {
            lista.retirarAtual();
            break;
        }
        case 'x': case 'X': {
            return;
        }
        default: {
            std::cout << "Opção inválida!\n";
            break;
        }
        }
    }
}

int main() {
    ListaDupla lista;
    menu(lista);
    return 0;
}
