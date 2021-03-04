#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    istringstream stream;

    if(argc < 3){
        cout << "Erro! Não foram informados os parâmetros necessários para a execução do sistema" << endl;
        return -1;
    }

    ifstream arqEntrada(argv[1]); 
    string linha_entrada = "";
    string nomePlaneta = "";
    int distancia;

    //TODO Criar Lista de Planeta de tamanho argv[2]
    int i = 0;
    if(arqEntrada.is_open()){
        while(i < atoi(argv[2])){
            getline(arqEntrada, linha_entrada);
            stream = istringstream(linha_entrada);
            stream >> nomePlaneta >> distancia;

            //TODO Planeta[i] = new Planeta(nomePlaneta, distancia);
            i++;
        }
        arqEntrada.close();
    } else {
        cout << "Erro! Arquivo " << argv[1] << " não foi encontrado" << endl;
        return -1;
    }
    
    // TODO: Ordenar

    // TODO: Imprimir 7 primeiras posições

    return 0;
}