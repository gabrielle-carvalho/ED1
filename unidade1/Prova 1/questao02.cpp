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
        if (inicio == nullptr) {
            novo->ant = nullptr;
            novo->prox = nullptr;
            inicio = novo;
            atual = novo;
            return;
        }
        novo->prox = atual->prox;
        novo->ant = atual;
        if (atual->prox != nullptr) {
            atual->prox->ant = novo;
        }
        atual->prox = novo;
        atual = novo;
    }
 
    void retirar() {
        if (atual == nullptr) {
            std::cout << "Sem elementos para retirar\n";
            return;
        }
        Nodo *aux = atual;
        if (aux->ant != nullptr) {
            aux->ant->prox = aux->prox;
        } else {
            inicio = aux->prox;
        }
        if (aux->prox != nullptr) {
            aux->prox->ant = aux->ant;
            atual = aux->prox;
        } else {
            atual = aux->ant;
        }
        delete aux;
    }
 
    void retirarN(Nodo* no, int n) {
        Nodo* aux = no;
        while (aux != nullptr) {
            if (aux->info == n) {
                Nodo* anterior = aux->ant;
                Nodo* proximo = aux->prox;
                if (anterior != nullptr) {
                    if (anterior->ant != nullptr)
                        anterior->ant->prox = aux;
                    else
                        inicio = aux;
                    aux->ant = anterior->ant;
                    delete anterior;
                }
                if (proximo != nullptr) {
                    if (proximo->prox != nullptr)
                        proximo->prox->ant = aux;
                    aux->prox = proximo->prox;
                    delete proximo;
                }
                return;
            }
            aux = aux->prox;
        }
        std::cout << "Elemento " << n << " não encontrado na lista\n";
    }
 
    void listar() {
        Nodo *tmp = inicio;
        std::cout << "Lista: ";
        while (tmp != nullptr) {
            std::cout << tmp->info << " ";
            tmp = tmp->prox;
        }
        std::cout << "\n";
    }
 
    Nodo* getInicio() {
        return inicio;
    }
};
 
void menu(ListaDupla &lista) {
    char opcao;
    while (true) {
        std::cout << "\nD: Inserir (após atual)\n";
        std::cout << "S: Eliminar atual\n";
        std::cout << "N: Eliminar antecessor e sucessor de um valor\n";
        std::cout << "L: Listar\n";
        std::cout << "X: Sair\n";
        std::cout << "Digite sua opção: ";
        std::cin >> opcao;
        switch (opcao) {
            case 'd':
            case 'D': {
                int num;
                std::cout << "Insira o número: ";
                std::cin >> num;
                lista.inserir(num);
                break;
            }
            case 's':
            case 'S': {
                lista.retirar();
                break;
            }
            case 'n':
            case 'N': {
                int num;
                std::cout << "Informe o valor para retirar antecessor e sucessor: ";
                std::cin >> num;
                lista.retirarN(lista.getInicio(), num);
                break;
            }
            case 'l':
            case 'L': {
                lista.listar();
                break;
            }
            case 'x':
            case 'X':
                return;
            default:
                std::cout << "Opção inválida\n";
        }
    }
}
 
int main() {
    ListaDupla lista;
    menu(lista);
    return 0;
}
