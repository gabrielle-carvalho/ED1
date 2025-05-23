/*5. Considere uma lista simplesmente encadeada que armazene números em
ordem crescente. Escreva uma função, em C++, que receba esta lista, e remova o
nó antecessor e o sucessor a um determinado nó contendo um elemento X
(inteiro).
*/
void removeX(int x){

    if(inicio==nullptr){
        std::cout<<"Lista vazia"<<std::endl;
        return;
    }

    Nodo*ant=nullptr;
    Nodo*atual=inicio;

    while(atual!=nullptr && atual->info!=x){
        ant=atual;
        atual=atual->prox;
    }

    if(atual==nullptr){
        std::cout<<"Não encontrado: " << x << std::endl;
        return;
    }
    if(ant!=nullptr){
        Nodo *antecessor=nullptr;
        Nodo *aux=inicio;
        while(aux!=nullptr && aux->prox != ant){
            aux=aux->prox;
        } //perocre todo array ate achar o que vem antes de ant
        antecessor=aux;
        if(antecessor==nullptr){
            inicio=atual;
            delete ant;
        }
        else{
            antecessor->prox=atual;
            delete ant;
        }
    }
    Nodo *prox =atual->prox;
    if(prox!=nullptr){
        atual->prox =prox->prox;
        delete prox;
    }
}