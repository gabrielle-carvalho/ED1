#include <iostream>
#define MAX 10

class Pilha{

  private: //lista de atributos em privado
    int topo; //psica d ultim element clcad na fila
    int v[MAX]; //para guardar s valres da pilha

  public: //decaracao de metodos
  
    Pilha(){ //contrutor de mesmo nome da classe
      topo = -1; //começa com -1 para que quando seja incrementado va pra 0
    }

    bool pilhaCheia(){
      return topo ==MAX-1;
    }
    bool pilhaVazia(){
      return topo== -1;
    }
    
    void empilhar(int n){
      if(pilhaCheia()){
        std::cout<<"Pilha cheia!" <<std::endl;
        return;
      } //verifica se a pilha esta cheia antes de retirar
      ++topo;
      v[topo] = n;
    }
    
    void desempilhar(){
      if(pilhaVazia()){
        std::cout<<"pilha vazia"<<std::endl;
        return -1;
      }
      int n =v[topo];
        // v[topo]=0;
        --topo;
      return n;
    }

    void mostrar(){
      if(pilhaVazia()){
        std::cout<<"pilha vazia"<<std::endl;
        return;
      }
      std::cout<<"Pilha"<<std::endl;
      for(int i=topo; i=0; i--){
        std::cout<< v[i] <<" ";
      }
      std::cout<<std::endl;
    }
    
};

int main() {
    Pilha p;
    p.empilhar(10);
    p.empilhar(20);
    p.empilhar(30);
    p.mostrar();

    std::cout << "Desempilhado: " << p.desempilhar() << std::endl;
    p.mostrar();
}
