#include <iostream>
#include <string>

struct Nodo{
  string info;
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
  
  void editar(string palavra){
      if(atual!=nullptr){
        atual->info=palavra;
      }
    }

  void inserir(string n){
    Nodo *novo=new Nodo();
    novo->info=n;
    
    if(inicio==nullptr){
      novo->ant=novo;
      novo->prox=novo;
      inicio=novo;
      atual=novo;
      return;
    }

    else {
      novo->prox = atual->prox;
      novo->ant = atual;
      atual->prox->ant = novo;
      atual->prox = novo;
    }

    // else{
    //   novo->prox=atual->prox;
    //   atual->prox->ant=novo;
    //   atual->prox=novo;
    //   novo->ant=atual;
    // }
  }

  void retirarAtual(){
    if(atual==nullptr){
      return;
    }
    if((atual==inicio)&&(atual==fim)){
      cout<<"Único elemento retirado";
      inicio=nullptr;
      fim=nullptr;
      delete atual;
    }
    else if (atual==inicio){
      atual->prox->ant=atual->ant; //=fim;
      atual->ant->prox=atual->prox;
      atual->prox=inicio;
      delete atual;
    }
    else if(atual==fim){
      atual->ant->prox=atual->prox;
      atual->prox->ant=atual->ant;
      atual->ant=fim;
      delete atual;
    }
    else{
      atual->ant->prox=atual->prox;
      atual->prox->ant=atual->ant;
      delete atual;
    }
  }

  void retirarEscolhida(string n){
    if(atual==nullptr){
      return;
    }
    Nodo *temp=inicio;

    while((atual->info != n) && (atual->prox!=inicio)){
      atual=atual->prox;
    }

    if (atual->info == n){
      atual->ant->prox=atual->prox;
      atual->prox->ant=atual->ant;
    }

    else if ((atual->prox==inicio)&&(n != atual->info)){
      cout << "Número não está na lista para se retirar";
    }

    delete atual;
  }

  void percorrer (string s){
    if(atual==nullptr){
      return;
    }

    if(s == "<"){
      atual=atual->ant;
    }

    else if(s == ">"){
      atual=atual->prox;
    }
  }

  string getAtual(){
    if(atual!=nullptr){
      return atual->info;
    }
    return "Vazio";
  }

  void frase(){
    if (inicio == nullptr) {
      cout << "Lista vazia.\n";
      return;
    }
    Nodo *temp = inicio;
    while (temp!=inicio){
      cout<< temp->info << " ";
      temp=temp->prox;
    }
    
  }

}

string menu(ListaCircular &lista){
  string opcao;
  while(true){
    cout << "Palavra atual:"<< lista.getAtual()<<"\n";
    cout << "E: Editar palavra atual\n";
    cout << "D: Inserir (depois da palavra atual)\n";
    cout << "S: Eliminar palavra atual\n";
    cout << "A: Eliminar palavra escolhida\n";
    cout << "<: Palavra anterior\n";
    cout << ">: Palavra posterior\n";
    cout << "X: Sair\n";
    cout << "Digite sua opção: \n";
    cin>>opcao;

    if (opcao=="e" || opcao=="E"){
      string word;
      cout<<"Insira a palavra que você quer modificar na atual: ";
      cin>>word;
      lista.editar(word);
    }

    else if (opcao=="d" || opcao=="D"){
      string word;
      cout<<"Insira a palavra que você quer inserir após a atual: ";
      cin>>word;
      lista.inserir(word);
    }

    else if (opcao=="s" || opcao=="S"){
      lista.retirarAtual();
    }

    else if(opcao=="a" || opcao=="A"){
      string word;
      cout<<"Insira a palavra que você quer inserir remover: ";
      cin>>word;
      lista.retirarEscolhida(word);
    }
    
    else if(opcao=="<" || opcao==">"){
      lista.percorrer(opcao);
    }

    else if (opcao == "x" || opcao == "X") {
      break;
    }

    else{
      cout<<"insira uma opção válida!";
    }
  }  
}

int main(){  
  ListaCircular lista;
  // Nodo *inicio, *atual;
  // while (atual->prox!=inicio){
  //   cout << atual->info + " ";
  // }
  menu(lista);
  return 0;



}