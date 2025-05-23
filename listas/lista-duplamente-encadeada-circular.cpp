#include <iostream>
#include <string>

struct Nodo {
    std::string info;
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

    void inserir(std::string n) {
        Nodo *novo = new Nodo();
        novo->info = n;

        if (inicio == nullptr) {
            novo->ant = novo;
            novo->prox = novo;
            inicio = novo;
            atual = novo;
            return;
        }

        novo->prox = atual->prox;
        novo->ant = atual;
        atual->prox->ant = novo;
        atual->prox = novo;
        atual = novo;
    }

    void retirarAtual() {
        if (atual == nullptr) {
            std::cout << "Sem elementos para retirar\n";
            return;
        }

        if (atual->prox == atual) {
            std::cout << "Único elemento retirado\n";
            delete atual;
            inicio = nullptr;
            atual = nullptr;
        } else {
            Nodo *aux = atual;
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            if (atual == inicio) {
                inicio = atual->prox;
            }
            atual = atual->prox;
            delete aux;
        }
    }

    std::string getAtual() {
        if (atual != nullptr) {
            return atual->info;
        } else {
            return "[vazio]";
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
            std::string word;
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
