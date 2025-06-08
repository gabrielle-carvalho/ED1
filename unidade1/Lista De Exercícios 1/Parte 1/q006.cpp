/* 6. Escreva uma função, em C++, que receba uma lista simplesmente encadeada
contendo em cada nó um inteiro, e retorne uma outra lista contendo nas  primeiras
 posições os elementos pares em ordem decrescente, seguidos dos
elementos ímpares em ordem crescente.
OBS.: A função não deverá alocar nenhum nó, e todas as funções utilizadas na
resolução deverão ser implementadas.*/

#include <iostream>

struct Nodo {
    int info;
    Nodo* prox;
};

Nodo* separarOrdenarLista(Nodo* listaOriginal) {
    Nodo* pares = nullptr;
    Nodo* impares = nullptr;

    // Separa os elementos em duas listas: pares e ímpares
    while (listaOriginal != nullptr) {
        Nodo* atual = listaOriginal;
        listaOriginal = listaOriginal->prox;
        atual->prox = nullptr;

        if (atual->info % 2 == 0) {
            if (pares == nullptr) {
                pares = atual;
            } else {
                Nodo* aux = pares;
                while (aux->prox != nullptr)
                    aux = aux->prox;
                aux->prox = atual;
            }
        } else {
            if (impares == nullptr) {
                impares = atual;
            } else {
                Nodo* aux = impares;
                while (aux->prox != nullptr)
                    aux = aux->prox;
                aux->prox = atual;
            }
        }
    }

    // Ordena pares em ordem decrescente
    for (Nodo* i = pares; i != nullptr; i = i->prox) {
        for (Nodo* j = i->prox; j != nullptr; j = j->prox) {
            if (i->info < j->info) {
                // troca manual dos valores
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    // Ordena ímpares em ordem crescente
    for (Nodo* i = impares; i != nullptr; i = i->prox) {
        for (Nodo* j = i->prox; j != nullptr; j = j->prox) {
            if (i->info > j->info) {
                // troca manual dos valores
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    // Junta pares com ímpares
    if (pares == nullptr) return impares;

    Nodo* fim = pares;
    while (fim->prox != nullptr)
        fim = fim->prox;

    fim->prox = impares;

    return pares;
}
