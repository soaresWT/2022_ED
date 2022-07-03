#include <iostream>
#include <vector>

using namespace std;

const int MORTO = 0;

void mostrar_vetor(vector<int> v, int escolhido)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i == escolhido)
        {
            cout << "*";
        }
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl;
}

int procurar_prox_elemento(vector<int> v, int pos)
{
    int posicao = (pos + 1) % v.size();
    while (v[posicao] == MORTO)
    {
        posicao = (posicao + 1) % v.size();
    }
    return posicao;
}

int main()
{
    cout << "Tamanho vetor" << endl;
    int size = 0;
    cin >> size;
    vector<int> vetor;

    for (int i = 0; i < size; i++)
    {
        vetor.push_back(i + 1);
    }
    cout << "Digite o escolhido" << endl;
    int escolhido = 0;
    cin >> escolhido;

    mostrar_vetor(vetor, escolhido);
    int qtd = size;
    while (qtd > 1)
    {
        int posicao = procurar_prox_elemento(vetor, escolhido);
        vetor[posicao] = MORTO;
        escolhido = procurar_prox_elemento(vetor, posicao);
        mostrar_vetor(vetor, escolhido);
        qtd--;
    }
}