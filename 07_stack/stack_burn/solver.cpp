#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <time.h>

void show(vector<string> floresta)
{
    cout << '\n';
    for (auto line : floresta)
        cout << line << '\n';
}

struct Pos
{
    int l;
    int c;
    Pos(int l, int c)
    {
        this->l = l;
        this->c = c;
    };
};

bool verifica_limites(Pos pos, int linhas, int colunas)
{
    return pos.l >= 0 && pos.l < linhas && pos.c >= 0 && pos.c < colunas;
}
vector<Pos> pode_queimar(vector<string> &matriz, Pos v)
{
    vector<Pos> Queimar;
    int nl = matriz.size();
    int nc = matriz[0].size();

    for (int i = 0; i < (int)v.size(); i++)
    {
        if (!verifica_limites(v[i], nl, nc))
            return false;

        if (matriz[v[i].l][v[i].c] != '#')
            continue;

        Queimar.push_back(v[i]);
    }
    return Queimar;
}

void queimar(vector<string> &mat, size_t l, size_t c)
{
    stack<Pos> pilha;
    if (mat[l][c] != '#')
        return;
    mat[l][c] = 'o';

    pilha.push_back(make_pair(l, c));
    while (!pilha.empty())
    {
        auto Queimar = pode_queimar(mat, pilha.front());
        if (!Queimar.empty())
        {
            auto neib = Queimar.front();
            mat[neib.first][neib.second] = 'o';
            pilha.push_back(neib);
        }
        pilha.pop_back();
    }
}

int main()
{
    int nl, nc, l, c;
    cin >> nl >> nc >> l >> c;

    vector<string> mat(nl, string(nc, ' '));
    for (int i = 0; i < nl; i++)
        cin >> mat[i];

    queimar(mat, l, c);
    for (string line : mat)
        cout << line << "\n";
    return 0;
}