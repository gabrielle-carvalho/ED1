#include <iostream>
#include <string>

struct Nodo {
    std::string info;
    Nodo *prox;
};

class ListaSimples {
private:
    Nodo *inicio;
    Nodo *atual;
public:
    ListaSimples() {
        inicio = nullptr;
        atual = nullptr;
    }

    void inserir(std::string n) {
        Nodo *novo = new Nodo();
        novo->info = n;
        novo->prox = nullptr;

        if (inicio == nullptr) {
            inicio = novo;
            atual = novo;
            return;
        }

        novo->prox = atual->prox;
        atual->prox = novo;
        atual = novo;
    }

    void retirarAtual() {
        if (atual == nullptr) {
            std::cout << "Sem elementos para retirar\n";
            return;
        }

        // Caso haja apenas um elemento
        if (inicio == atual && atual->prox == nullptr) {
            std::cout << "Único elemento retirado\n";
            delete atual;
            inicio = nullptr;
            atual = nullptr;
            return;
        }

        // Caso atual seja o primeiro
        if (atual == inicio) {
            Nodo *temp = atual;
            inicio = atual->prox;
            atual = inicio;
            delete temp;
            return;
        }

        // Caso geral: procurar anterior
        Nodo *anterior = inicio;
        while (anterior->prox != atual) {
            anterior = anterior->prox;
        }

        anterior->prox = atual->prox;
        delete atual;
        atual = anterior->prox != nullptr ? anterior->prox : inicio;
    }

    std::string getAtual() {
        if (atual != nullptr) {
            return atual->info;
        } else {
            return "[vazio]";
        }
    }
};

void menu(ListaSimples &lista) {
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
    ListaSimples lista;
    menu(lista);
    return 0;
}
