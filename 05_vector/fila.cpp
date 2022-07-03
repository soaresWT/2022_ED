#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i];
        if (i != (int)v.size() - 1)
        {
            os << ", ";
        }
    }
    return os;
}

vector<int> Quais_Sobraram(vector<int> fila, vector<int> sairam)
{
    vector<int> sobraram;
    unordered_set<int> sairam_set(begin(sairam), end(sairam));

    for (auto elem : fila)
    {
        if (sairam_set.find(elem) == sairam_set.end())
            sobraram.push_back(elem);
    }
    return sobraram;
}

void Finalizar(vector<int> &vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        int line;
        cin >> line;
        vetor.push_back(line);
    }
}

int main()
{
    int n{0};
    cin >> n;
    vector<int> fila;
    fila.reserve(n);

    Finalizar(fila, n);

    int m{0};
    cin >> m;
    vector<int> desistentes;
    desistentes.reserve(m);

    Finalizar(desistentes, m);
    cout << Quais_Sobraram(fila, desistentes) << '\n';

    return 0;
}