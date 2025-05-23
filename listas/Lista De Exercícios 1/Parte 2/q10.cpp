/*
10. Considerando uma lista duplamente encadeada (dinâmica) contendo
números inteiros, escreva uma função, em C++, para eliminar todos os elementos
múltiplos de três e retornar uma fila contendo estes elementos (ordenados).

*/
Nodo *multiplosdeTres(Nodo *&lista){
    Nodo *fila=nullptr;
    Nodo *atual=lista;
    while(atual!=nullptr){
        Nodo *prox = atual->prox;
        if(atual->info %3 == 0){
            if(atual->ant!=nullptr){
                atual->ant->prox = atual->prox;
            }
            else{
                lista=atual->prox;
            }
            if(atual->prox !=nullptr){
                atual->prox->ant = atual->ant;
            }
            Nodo *novo = new Nodo;
            novo->info=atual->info;
            novo->ant=nullptr;
            novo->prox=nullptr;

            if(fila ==nullptr || novo->info < fila->info){
                novo->prox=fila;
                if(fila!=nullptr){
                    fila->ant=novo;
                }
                fila=novo;
            } else{
                Nodo *temp=fila;
                while(temp->prox!=nullptr&& temp->prox->info < novo->info){
                    temp=temp->prox;
                }
                novo->prox = temp->prox;
                if(temp->prox !=nullptr){
                    temp->prox->ant = novo;
                }
                temp->prox = novo;
                novo->ant =temp;
            }
            delete atual;
        }
        atual=prox;
    }
    return fila;
}