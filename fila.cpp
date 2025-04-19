#include <iostream>
#define MAX 10

class Fila{

private: //lista de atributos em privado
  int fim; //indice d ultim element inserid
  int v[MAX]; //vetr fix para armazenar a fila

public:
    Fila() { //cntrutr
        fim = -1; //cmeca vazia
    }
    
    void add(int n){
        if(filaCheia()){
            std::cout << "Fila cheia" << std::endl;
            return;
        }
        else{
            ++fim; // anda uma pscica n vetr
            v[fim] = n; //adicina mais um element n fim        
        }
    }
    
    bool filaCheia(){
      return (fim==MAX-1);
    }

    bool filaVazia(){
      return (fim == -1);
    }
    
    int retirar(){
      if(filaVazia()){
       std::cout << "Fila vazia, não dá pra tirar" << std::endl;
       return -1;
      } 
      
      int n=v[0];
      for(int i = 1; i<=fim; i++){
         v[i-1]=v[i];
      }
      fim--;
      return n;
    }

    void mostrar(){
      if(filaVazia()){
        std::cout<<"Fila vazia"<<std::endl; //endl é para pular linha: \n
        return;
      }
      std::cout<<"Fila: ";
      for(int i=0; i<=fim; i++){
        std::cout<<v[i] << " ";
      }
      std::cout <<std::endl;
    }
    
};

int main(){
    Fila obj1;
    obj1.add(10);
    obj1.add(20);
    obj1.mostrar();
    std::cout << "Retirado: " << obj1.retirar() << std::endl;
    obj1.mostrar();
    std::cout << "Retirado: " << obj1.retirar() << std::endl;
    obj1.mostrar();
    std::cout << "Retirado: " << obj1.retirar() << std::endl; // Teste com fila vazia
}
