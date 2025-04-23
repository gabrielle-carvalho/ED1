

void inserirOrdenado(int n){
  Nodo *novo, *ant, *atual;
  novo = new Nodo();
  if(novo==nullptr)
    return;
  novo->info=n;
  if(inicio==nullptr){
    novo->prox = nullptr;
    inicio=novo;
    return;
  }
  atual=inicio;
  while((atual != nullptr) && (novo->info > atual->info)){
    ant=atual;
    atual=atual->info;
  }
  if(atual==nullptr){
    ant->prox=novo;
    novo->prox=nullptr;
  }
  else if(atual==inicio){
    novo->prox=inicio;
    inicio=novo;
  }
  else{
    ant->prox=novo;
    novo->prox=atual;
  }
}

void retirarElemento(int n){
  Nodo *ant, *atual;
  if(inicio==nullptr){
    cout<<"Lista vazia";
    return
  }
  atual=inicio;
  while((atual!=nullptr) && (atual->info != n){
    ant=atual;
    atual=atual->prox
    if(atual==nullptr)
      cout<<"Número nao encontrado";
      return;
    if (atual==inicio)
      inicio=atual->prox;
    else
      ant->prox=atual->prox;
    delete atual;
    
      
  }
  
  // if(atual->prox==nullptr)
  //   ant->prox=nullptr; //ver pq esse é desnecessario
  // else if (atual==inicio)
  //   inicio=atual->prox;
  // else
  //   ant->prox=atual->prox;
  
}


int listarElementos(){
  
}
