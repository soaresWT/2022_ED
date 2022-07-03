#include <iostream>
#include <vector>
using namespace std;

/*
 * base 1 2 3
 * soma 1 + 2 = 3
 * soma 2 + 3 = 5
 * segunda linha
 *  3 5
 * soma 3 + 5 = 8
 * ultima linha 8 acaba o problema
 * somar posicao + posicao + 1 = uma posicao do proximo vetor, sucessivamente ate chegar no ultimo
 */

void show(vector<int> vet)
{
    cout << "[";
    for (auto x : vet)
        cout << " " << x;
    cout << " ]\n";
}

void somar(vector<int> vet)
{
    if (vet.size() == 1)
        return;
    vector<int> aux;
    for (int i = 0; i < vet.size() - 1; i++)
        aux.push_back(vet[i] + vet[i + 1]);
    somar(aux);
    1 show(aux);
}

int main()
{
    cout << "Quantidade de numeros: ";
    int n;
    cin >> n;
    vector<int> vet;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vet.push_back(x);
    }

    somar(vet);
    show(vet);
}