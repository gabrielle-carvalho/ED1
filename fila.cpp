#include <iostream>
#define MAX 10

class Fila{

  private: //lista de atributos em privado
    int fim;
    int v[MAX];

  public: //decaracao de metodos
    Fila(){ //contrutor de mesmo nome da classe
      fim = -1; //começa com -1 para que quando seja incrementado va pra 0
    }
    
    void add(int n){
        if(fim ==MAX-1){
            std::cout << "Fila cheia" << std::endl;
            return;
        }
        else{
            ++fim;
            v[fim] = n;
        }
    }
    
    //filaCheia()
    
    int retirar(){
      while(fim == -1){
       std::cout << "Fila vazia, não dá pra tirar" << std::endl;
       return;
      } 
      n=v[0];
      else{
        for(int i = 1; i<=fim; i++){
           v[i-1]=v[i];
           fim--;
        }
      }
    }
    
};

int main(){
      Pilha obj1;
      
    }
