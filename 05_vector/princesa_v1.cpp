#include <iostream>
#include <vector>

using namespace std;

void show_vector(vector<int> vetor, int escolhido)
{
    cout << "[";
    for (int i = 0; i < vetor.size(); i++)
    {
        if (i == escolhido)
        {
            cout << "*";
        }
        cout << vetor[i];
        if (i != vetor.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    cout << "--" << vetor.size() << endl;
    cout << endl;
}
int next_element(vector<int> vetor, int pos)
{
    return (pos + 1) % vetor.size();
}
int main()
{
    cout << "Tamanho vetor" << endl;
    int size = 0;
    cin >> size;

    vector<int> vetor;
    for (int i = 0; i < size; i++)
        vetor.push_back(i);

    cout << "Digite o escolhido" << endl;
    int escolhido = 0;
    cin >> escolhido;
    escolhido = escolhido - 1;

    show_vector(vetor, escolhido);

    int qtd = size - 1;
    while (qtd--)
    {
        int posicao = next_element(vetor, escolhido);
        cout << "posicao: " << posicao << endl;
        vetor.erase(vetor.begin() + posicao);
        escolhido = next_element(vetor, posicao - 1);
        show_vector(vetor, escolhido);
    }
}
