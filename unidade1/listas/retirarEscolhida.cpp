  void retirarEscolhida(std::string n){
    if(atual==nullptr){
        std::cout << "Lista vazia.\n";
      return;
    }
    Nodo *aux=inicio;
    bool encontrou = false;

    do{
      if (aux->info==n){
        if(aux==atual){
          retirarAtual();
        }
        else{
          aux->ant->prox=aux->prox;
          aux->prox->ant=aux->ant;
          if (aux==inicio){
            inicio=aux->prox;
          }
          delete aux;
        }
        return;
      }
      aux=aux->prox;
    }while(aux != inicio);
    std::cout<<"Palavra não encontrada"<<std::endl;
  }

        case 'a': case 'A': { 
            std::string word;
            std::cout<<"Insira a palavra que você quer remover: ";
            std::cin>>word;
            lista.retirarEscolhida(word);
            break;
        }

    std::cout << "A: Eliminar palavra escolhida\n";
