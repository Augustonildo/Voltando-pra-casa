#include "Pilha.hpp"
#include <stdlib.h>

#define MAXTAM 100

template <typename T> 
Pilha<T>::Pilha(){
    this->tamanho = 0;
    this->tamanhoMaximo = MAXTAM;
    itens = (T *) malloc(tamanhoMaximo * sizeof(T));
}

template <typename T> 
Pilha<T>::Pilha(int tamanhoMaximo){
    this->tamanho = 0;
    this->tamanhoMaximo = tamanhoMaximo;
    itens = (T *) malloc(tamanhoMaximo * sizeof(T));
}

template <typename T> 
Pilha<T>::~Pilha(){
    free(itens);
}

template <typename T> 
T Pilha<T>::Desempilha(){
    if(Vazia()) throw "A pilha está vazia!";
    tamanho--;
    T aux = itens[tamanho];
    return aux;
}

template <typename T> 
void Pilha<T>::Empilha(T item){
    if(tamanho == tamanhoMaximo) throw "A pilha está cheia!";
    itens[tamanho] = item;
    tamanho++;
}

template <typename T> 
void Pilha<T>::Limpa(){
    this->tamanho = 0;
    free(this->itens);
}

template <typename T> 
bool Pilha<T>::Vazia(){
    return tamanho == 0;
}

template class Pilha<Item>;