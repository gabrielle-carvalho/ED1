

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

