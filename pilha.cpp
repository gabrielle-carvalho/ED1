#include <iostream>
#define MAX 10

class Pilha{

  private: //lista de atributos em privado
    int topo;
    int v[MAX];

  public: //decaracao de metodos
  
    Pilha(){ //contrutor de mesmo nome da classe
      topo = -1; //começa com -1 para que quando seja incrementado va pra 0
    }
    
    void empilhar(int n){
      ++topo;
      v[topo] = n;
    }
    
    void desempilhar(){
      while(topo!= -1){
        v[topo]=0;
        --topo;
      }
    }
    
};

int main(){
      Pilha obj1;
      
    }
