#include "Planeta.hpp"
#include <fstream>
#include <sstream>

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
    
    // TODO: Ordenar
    
    for(int j = 0; j < 7; j++){
        cout << planetas[j].GetNome() << " " << planetas[j].GetDistancia() << endl; 
    }

    return 0;
}