#include <iostream>
using namespace std;

struct Nodo{
  int info;
  Nodo *prox;
};

class PilhaD{
private:
  Nodo *topo;
public:
  PilhaD(){
    topo=nullptr;
  }
  void empilhar(int n){
    Nodo *novo = new Nodo;
    novo->info=n;
    novo->prox=topo;
    topo=novo;
  }

  int desempilhar() {
    if (topo != nullptr) {
        Nodo* aux = topo;
        topo = topo->prox;
        int n = aux->info;
        delete aux;
        return n;
    } else {
        cout << "Pilha vazia" << endl;
        return -1;
    }
    }
  
  bool vazia() {
      return topo == nullptr;
  }
  
  void listar() {
      Nodo* aux = topo;
      while (aux != nullptr) {
          cout << aux->info << endl;
          aux = aux->prox;
      }
  }
  
  void ordenarCrescente() {
    PilhaD aux; //ajudar a rdenar
    while (!vazia()) {
        int temp = desempilhar();
        while (!aux.vazia() && aux.topo->info > temp) {        // Coloca os elementos maiores de volta na pilha original
            empilhar(aux.desempilhar());
        }
        aux.empilhar(temp);
    }
    while (!aux.vazia()) {    // Copia ordenada de volta pra pilha original
        empilhar(aux.desempilhar());
    }
  }
};

int main() {
    PilhaD pilha;
    pilha.empilhar(5);
    pilha.empilhar(2);
    pilha.empilhar(8);
    pilha.empilhar(1);

    cout << "Pilha original:" << endl;
    pilha.listar();

    pilha.ordenarCrescente();

    cout << "\nPilha ordenada (crescente):" << endl;
    pilha.listar();

    return 0;
}
