typedef struct Item
{
    int direita;
    int esquerda;
} Item;

template <typename T> 
class Pilha
{
    public:
        Pilha();
        Pilha(int tamanhoMaximo);
        ~Pilha();
        T Desempilha();
        void Empilha(T comando);
        void Limpa();
        bool Vazia();
        
    private:
        int tamanho;
        int tamanhoMaximo;
        T *itens;
};