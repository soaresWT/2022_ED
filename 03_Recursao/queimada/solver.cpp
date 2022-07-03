#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void show(vector<string> mapa)
{
    for (auto line : mapa)
        cout << line << '\n';
    cout << '\n';
}

void queimar(vector<string> &mapa, int lpos, int cpos)
{
    int ln = mapa.size();
    int nc = mapa[0].size();

    if (lpos < 0 || lpos >= ln || cpos < 0 || cpos >= nc)
        return;
    if (mapa[lpos][cpos] != '#')
        return;

    mapa[lpos][cpos] = 'x';
    show(mapa);

    queimar(mapa, lpos, cpos - 1);
    queimar(mapa, lpos - 1, cpos);
    queimar(mapa, lpos, cpos + 1);
    queimar(mapa, lpos + 1, cpos);

    mapa[lpos][cpos] = '*';
    show(mapa);
}

int main()
{
    vector<string> mapa;
    ifstream arq("input.text");
    int nl{0}, nc{0}, li{0}, ci{0};
    arq >> nl >> nc >> li >> ci;

    for (int i = 0; i < nl; i++)
    {
        string line;
        arq >> line;
        mapa.push_back(line);
    }

    queimar(mapa, li, ci);

    show(mapa);
}