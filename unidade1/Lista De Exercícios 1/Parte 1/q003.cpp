/* Escreva uma função, em C, que receba duas listas simplesmente encadeadas
A e B, contendo informações (Código e Nome) dos pacientes do médico X e do
médico Y (respectivamente), de uma determinada clínica. A clínica deseja
possuir uma lista única com as informações dos pacientes desses dois médicos
a partir da junção dessas duas listas. Considere que as listas A e B estão
ordenadas por código de pacientes e que não existem dois (ou mais) pacientes
com o mesmo código. A lista resultante deve conter todos os pacientes dos
médicos X e Y ordenados por código e sem elementos repetidos.
OBS.: A função não deverá alocar nenhum nó, e todas as funções utilizadas na
resolução deverão ser implementadas.
 */
Nodo *intercalarListas(Nodo *A, Nodo *B){
    Nodo *inicio=nullptr;
    Nodo *fim=nullptr;
    while(A!=nullptr && B!=nullptr){
        Nodo *menor=nullptr;
        if(A->codigo < B->codigo){
            menor=A;
            A = A->prox;
        }
        else if(B->codigo < A->codigo){
            menor=B;
            B=B->prox;
        }
        else{
            menor=A;
            A=A->prox;
            B=B->prox;
        }
        
        if (inicio==nullptr){
            inicio=menor;
            fim=menor;
        }
        else {
            fim->prox=menor;
            fim=menor;
        }
    }

    while(A!=nullptr){
        if(fim==nullptr || fim->codigo !=A->codigo){
            fim->prox=A;
            fim=A;
            A=A->prox;
        }
        else{
            A=A->prox;
        }
    }
    while(B!=nullptr){
        if(fim==nullptr || fim->codigo != B->codigo){
            fim->prox=B;
            fim=B;
            B=B->prox;
        }
        else{
            B=B->prox;
        }
    }
    if(fim!=nullptr){
        fim->prox = nullptr;
    }
    return inicio;
}