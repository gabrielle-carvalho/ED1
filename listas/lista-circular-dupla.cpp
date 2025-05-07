#include <iostream>
using namespace std;

struct Nodo{
  int info;
  struct Nodo *ant, *prox;
};

Class ListaDupla{
  Nodo * inicio;
  ListaDupla(){
    inicio=nullptr;
  }
  void inserir(int n);
  void retirar(int n);
  void listar();
}

ListaDupla::inserir(int n){
  Nodo *novo, *atual, *fim;
  novo=new Nodo();
  
  if(novo==nullptr)
    return;
  
  novo->info = n;
  
  if(inicio==nullptr){
    novo->ant=novo;
    novo->prox=novo;
    inicio=novo;
    fim=novo;
    return;
  }
  // atual=inicio;
  else if (atual -> prox == inicio){
    novo->prox=inicio;
    inicio->ant=novo;
    fim->prox=novo;
    novo->ant=fim;
    fim=novo;
  }
  else{
    novo->prox=atual->prox;
    atual->prox->ant=novo;
    atual->prox=novo;
    novo->ant=atual;
  }


//   if (atual -> prox == inicio){ //é no fim}
//     aux->prox=inicio;
//     inicio->ant=novo;
//     atual->prox=novo; //atual
//     novo->ant=atual;
//     novo->prox=inicio; //ou aux
// }
//   else{
//     novo->prox=inicio;
//     inicio->ant=fim;
//     atual->prox=novo;
//     novo->ant=atual;
//   }
  
}
