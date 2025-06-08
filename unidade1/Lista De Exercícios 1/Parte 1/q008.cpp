/* 8. Uma maneira de representar um conjunto é pela lista de seus elementos.
Supondo esta representação, escreva uma função, em C, que receba duas
listas simplesmente encadeadas e implemente a operação de interseção. O
resultado final deve ser apresentado através de uma outra lista simplesmente
encadeada (estática). */

Nodo *intersecao(Nodo * l1, Nodo *l2){
    Nodo *resultado=nullptr;
    Nodo *fim=nullptr;

    for (Nodo* i = l1; i != nullptr; i = i->prox) {
        for (Nodo* j = l2; j != nullptr; j = j->prox) {
            if (i->info == j->info) {
                bool jaExite=false;
                for(Nodo *k=resultado; k!=nullptr; k=k->prox){
                    if(k->info==i->info){
                        jaExite=true;
                        break;
                    }
                }
                if(!jaExite){
                    Nodo *novo=new Nodo();
                    novo->info = i->info;
                    novo->prox = nullptr;
                    if(resultado==nullptr){
                        resultado=novo;
                        fim=novo;
                    }
                    else{
                        fim->prox=novo;
                        fim=novo;
                    }
                }
                break;
            }
        }
    }
    return resultado;
}