#include <iostream>
#include <vector>
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

vector<int> deuMatch(vector<string> consultas, vector<string> buscar)
{
    vector<int> Match(buscar.size(), 0);

    for (int i = 0; i < buscar.size(); i++)
        for (int j = 0; j < consultas.size(); j++)
            if (consultas[j] == buscar[i])
                Match[i]++;
    return Match;
}

int main()
{
    int size;

    cin >> size;
    vector<string> base(size, "");
    for (int i = 0; i < size; i++)
        cin >> base[i];

    cin >> size;
    vector<string> consulta(size, "");
    for (int i = 0; i < size; i++)
        cin >> consulta[i];

    cout << deuMatch(base, consulta) << endl;

    return 0;
}