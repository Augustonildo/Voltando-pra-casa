#include "Planeta.hpp"

Planeta::Planeta(){ }

Planeta::Planeta(string nome, int distancia){
    this->nome = nome;
    this->distancia = distancia;
}

int Planeta::GetDistancia(){
    return distancia;
}

string Planeta::GetNome(){
    return nome;
}

void Planeta::SetDistancia(int distancia){
    this->distancia = distancia;
}

void Planeta::SetNome(string nome){
    this->nome = nome;
}