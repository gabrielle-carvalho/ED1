#include <iostream>
#include <string>

struct Nodo{
  std::string info;
  struct Nodo *ant, *prox;
};

class ListaCircular{
  private:
    Nodo *inicio;
    Nodo *atual;
  public:
    ListaCircular(){
        inicio=nullptr;
        atual=nullptr;
    }

    ~ListaCircular() { //destrutor que libera memoria
        if (inicio == nullptr) {
            return;
        }

        Nodo* atual = inicio->prox;
        while (atual != inicio) {
            Nodo* temp = atual;
            atual = atual->prox;
            delete temp;
        }
        delete inicio;
        inicio = nullptr;
    }

  void editar(std::string palavra){
      if(atual!=nullptr){
        atual->info=palavra;
      }
    }

  void inserir(std::string n){
    Nodo *novo=new Nodo();
    novo->info=n;
    
    if(inicio==nullptr){
      novo->ant=novo;
      novo->prox=novo;
      inicio=novo;
      atual=novo;
      return;
    }

    novo->prox = atual->prox;
    novo->ant = atual;
    atual->prox->ant = novo;
    atual->prox = novo;
    atual=novo;
  }

  void retirarAtual(){
    if(atual==nullptr){
      std::cout<<"Sem elementos para retirar"<<std::endl;
      return;
    }
    if(atual->prox==atual){
      std::cout<<"Único elemento retirado"<<std::endl;
      inicio=nullptr;
      atual=nullptr;
    }
    else {
      Nodo *aux= atual;
      aux->ant->prox = aux->prox;
      aux->prox->ant=aux->ant;
      if (atual==inicio){
        inicio=atual->prox;
      }
      atual=atual->prox;
      delete aux;
    }
  }
  
  void percorrer (char s){
    if(atual==nullptr){
        std::cout << "Lista vazia.\n";
        return;
    }
    if(s == '<'){
        atual=atual->ant;
    }
    else if(s == '>'){
      atual=atual->prox;
    }
  }

  std::string getAtual(){
    if(atual!=nullptr){
      return atual->info;
    }
    return "Vazio";
  }

  void frase() {
    if (inicio == nullptr) {
        std::cout << "Lista vazia.\n";
        return;
    }
    Nodo *aux = inicio;
    do {
        std::cout << aux->info;
        aux = aux->prox;
        if(aux!=inicio){
            std::cout<<"\n";
        }
    } while (aux != inicio);
    std::cout << "\n";
}

};

void menu(ListaCircular &lista){
  char opcao;
  while(true){
    lista.frase();
    std::cout << "Palavra atual:"<< lista.getAtual()<<"\n";
    std::cout << "E: Editar palavra atual\n";
    std::cout << "D: Inserir (depois da palavra atual)\n";
    std::cout << "S: Eliminar palavra atual\n";
    std::cout << "<: Palavra anterior\n";
    std::cout << ">: Palavra posterior\n";
    std::cout << "X: Sair\n";
    std::cout << "Digite sua opção: \n";
    std::cin>>opcao;

    switch (opcao) {
        case 'e': case 'E': {
            std::string word;
            std::cout << "Insira a palavra que você quer modificar na atual: ";
            std::cin >> word;
            lista.editar(word);
            break;
        }

        case 'd': case 'D': { 
            std::string word;
            std::cout<<"Insira a palavra que você quer inserir após a atual: ";
            std::cin>>word;
            lista.inserir(word);
            break;
        }

        case 's': case 'S': {
            lista.retirarAtual();
            break;
        }
   
        case '<': case '>': {
                lista.percorrer(opcao);
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

int main(){  
  ListaCircular lista;
  menu(lista);
  return 0; //chama destrutor
}
