#include <iostream>
using namespace std;

class Planeta
{
    public:
        Planeta();
        Planeta(string nome, int distancia);
        int GetDistancia();
        string GetNome();
        void SetDistancia(int distancia);
        void SetNome(string nome);

    private:
        int distancia;
        string nome;
};