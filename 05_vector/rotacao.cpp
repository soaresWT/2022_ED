#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v)
{
    os << "[ ";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i];
        if (i != (int)v.size() - 1)
            os << ", ";
    }
    os << " ]";
    return os;
}

void rotacionar(vector<int> &vet, int rotacao)
{
    if (rotacao <= 0)
        return;

    int tam = vet.size() - 1;
    int primeiro = vet[tam];

    for (int i = tam; i >= 0; i--)
        vet[i] = vet[i - 1];

    vet[0] = primeiro;
    rotacionar(vet, rotacao - 1);
}

int main()
{
    int size;
    cin >> size;
    vector<int> vet(size);
    for (int i = 0; i < size; i++)
    {
        stringstream ss;
        string s;
        cin >> s;
        ss << s;
        ss >> vet[i];
    }

    int rotacao;
    cin >> rotacao;

    rotacionar(vet, rotacao);
    cout << vet << endl;
}