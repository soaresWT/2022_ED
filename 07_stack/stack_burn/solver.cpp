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
    Pos(int l, int c) : l(l), c(c){};
};

struct Pos
{
    int l, c;

    Pos(int l, int c) : l(l), c(c) {}
};

bool pode_queimar(vector<string> &mat, Pos p)
{
    if (p.first < 0 || p.first >= mat.size())
        return false;
    if (p.second < 0 || p.second >= mat[0].size())
        return false;
    return true;
}

void queimar(vector<string> &mat, size_t l, size_t c)
{
    list<Pos> pilha;
    if (mat[l][c] != '#')
        return;
    mat[l][c] = 'o';
    pilha.push_back(make_pair(l, c));
    while (!pilha.empty())
    {
        auto top = pilha.back();
        vector<Pos> toburn;
        for (auto neib : get_neib(top))
        {
            if (pode_queimar(mat, neib) && (mat[neib.first][neib.second] == '#'))
            {
                toburn.push_back(neib);
                break;
            }
        }
        if (!toburn.empty())
        {
            auto neib = toburn.front();
            mat[neib.first][neib.second] = 'o';
            pilha.push_back(neib);
        }
        else
        {
            pilha.pop_back();
        }
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