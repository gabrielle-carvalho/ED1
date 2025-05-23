/* 4. Escreva uma função, em C++, para eliminar todos os elementos inteiros
repetidos em uma lista simplesmente encadeada. Considere que os elementos
nesta estrutura não estão ordenados. */

void eliminarRepetidos(){
    Nodo *atual, *novaLista, *aux, *fim;

    if(inicio==nullptr){
        std::cout<<"Lista vazia"<<std::endl;
        return;
    }

    Nodo *novaLista=nullptr;
    Nodo*fim=nullptr;

    while(inicio!=nullptr){
        Nodo *aux=inicio;
        inicio=inicio->prox;
        aux->prox=nullptr;

        Nodo *atual=novaLista;
        bool repetido=false;
        while(atual!=nullptr){
            if(atual->info == aux->info){
                repetido=true;
                break;
            }
            atual=atual->prox;
        }

        if(!repetido){
            if(novaLista==nullptr){
                novaLista=aux;
                fim=aux;
            }
            else{
                fim->prox=aux;
                fim=aux;
            }
        }
        else{
            delete aux;
        }
    }
    inicio=novaLista;
}