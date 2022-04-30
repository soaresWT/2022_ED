#include <iostream>
#include <vector>
using namespace std;

bool posso_inserir(string &line, int index, int value, int prox)
{
    for (int i = index + 1; i < index + 1 + prox; i++)
    {
        if (i < line.size() && line[i] == value + '0')
            return false;
    }
    for (int i = index - prox; i < index; i++)
    {
        if (i >= 0 && line[i] == value + '0')
            return false;
    }
    return true;
}
bool preencher(string &line, int index, int lim, int prox)
{
    if ((int)line.size() == index)
    {
        cout << line << "<----\n";
        return true;
    }
    if (line[index] != '.')
        return preencher(line, index + 1, lim, prox);
    for (int value = 0; value <= lim; value++)
    {
        if (posso_inserir(line, index, value, prox))
        {
            line[index] = value + '0';
            cout << line << '\n';
            if (preencher(line, index + 1, lim, prox))
                return true;
        }
    }
    line[index] = '.';
    cout << line << '\n';
    return false;
}

int main()
{
    string line;
    int proximidade;
    cin >> line >> proximidade;

    int limite = 1;
    while (!preencher(line, 0, limite, proximidade))
        limite++;
}