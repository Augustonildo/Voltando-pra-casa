#include "Planeta.hpp"
#include <fstream>
#include <sstream>

#define ALGORITMO_ORDENACAO 3

// ALGORITMO_ORDENACAO  1
void insertionSort(Planeta* planetas, int numeroPlanetas){
    int i,j;
    Planeta aux;
    for (i = 1; i < numeroPlanetas; i++) {
        aux = planetas[i];
        j = i - 1;
        while (( j >= 0 ) && (aux.GetDistancia() < planetas[j].GetDistancia())) {
            planetas[j + 1] = planetas[j];
            j--;
        }
        planetas[j + 1] = aux;
    }
} 

// ALGORITMO_ORDENACAO  2
void refaz(int esquerda, int direita, Planeta *planetas){
    int i = esquerda;
    int j = i * 2;
    Planeta aux = planetas[i];
    while (j <= direita){
        if (j < direita){
            if (planetas[j].GetDistancia() < planetas[j+1].GetDistancia()){
                j++;
            }
        }
        if (aux.GetDistancia() >= planetas[j].GetDistancia()) {
            break;
        }
        planetas[i] = planetas[j];
        i = j;
        j = i*2;
    }
    planetas[i] = aux;
}

void constroi(Planeta* planetas, int numeroPlanetas){
    int esquerda = numeroPlanetas / 2;
    while (esquerda >= 0) {
        refaz(esquerda, numeroPlanetas-1, planetas);
        esquerda--;
    }
}

void heapSort(Planeta* planetas, int numeroPlanetas){
    constroi(planetas, numeroPlanetas); 
    int esquerda = 0; 
    int direita = numeroPlanetas - 1;
    Planeta aux;
    while (direita >= 0)
    {
        aux = planetas[0];
        planetas[0] = planetas[direita];
        planetas[direita] = aux;
        direita--;
        refaz(esquerda, direita, planetas);
    }
}

// ALGORITMO_ORDENACAO  3
void particao(int esquerda, int direita, int *i, int *j, Planeta *planetas){
    *i = esquerda; 
    *j = direita;
    Planeta aux = planetas[(*i + *j)/2];
    Planeta w;
    do {
        while (aux.GetDistancia() > planetas[*i].GetDistancia()) (*i)++;
        while (aux.GetDistancia() < planetas[*j].GetDistancia()) (*j)--;
        if (*i <= *j)
        {
            w = planetas[*i];
            planetas[*i] = planetas[*j];
            planetas[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void ordena(int esquerda, int direita, Planeta *planetas){
    int i, j;
    particao(esquerda, direita, &i, &j, planetas);
    if (esquerda < j) ordena(esquerda, j, planetas);
    if (i < direita) ordena(i, direita, planetas);
}

void quickSort(Planeta* planetas, int numeroPlanetas){
    ordena(0, numeroPlanetas-1, planetas); 
}

// ALGORITMO_ORDENACAO  4
void quickSortModificado(Planeta* planetas, int numeroPlanetas){ }

// ALGORITMO_ORDENACAO  5
void adefinirSort(Planeta* planetas, int numeroPlanetas){ }

int main(int argc, char* argv[]) {
    istringstream stream;

    if(argc < 3){
        cout << "Erro! Não foram informados os parâmetros necessários para a execução do sistema" << endl;
        return -1;
    }

    int numeroLinhas;
    try {
        numeroLinhas = atoi(argv[2]);
    } catch (const string e){
        cout << "Erro ao tentar converter número de linhas para valor inteiro. Por favor, verifique o parâmetro correspondente. " << endl;
        cout << e << endl;
        return -1; 
    }

    ifstream arqEntrada(argv[1]); 
    string linha_entrada = "";
    string nomePlaneta = "";
    int distancia;

    Planeta planetas[numeroLinhas];
    int i = 0;
    if(arqEntrada.is_open()){
        while(i < atoi(argv[2])){
            getline(arqEntrada, linha_entrada);
            stream = istringstream(linha_entrada);
            stream >> nomePlaneta >> distancia;
            planetas[i] = Planeta(nomePlaneta, distancia);
            i++;
        }
        arqEntrada.close();
    } else {
        cout << "Erro! Arquivo " << argv[1] << " não foi encontrado" << endl;
        return -1;
    }
    
    switch (ALGORITMO_ORDENACAO)
    {
        case 1:
            insertionSort(planetas, numeroLinhas);
            break;
        case 2:
            heapSort(planetas, numeroLinhas);
            break;
        case 3:
            quickSort(planetas, numeroLinhas);
            break;
        case 4:
            quickSortModificado(planetas, numeroLinhas);
            break;
        case 5:
            adefinirSort(planetas, numeroLinhas);
            break;
        
        default:
            cout << "Erro! Algoritmo de ordenação definido incorretamente" << endl;
            return -1;
    }
    
    for(int j = numeroLinhas-1; j > numeroLinhas-8 && j >= 0; j--){
        cout << planetas[j].GetNome() << " " << planetas[j].GetDistancia() << endl; 
    }

    return 0;
}