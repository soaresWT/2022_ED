#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Pos
{
    int l;
    int c;
};
void show(vector<string> mapa)
{
    for (auto line : mapa)
        cout << line << '\n';

    cout << '\n';
}

// retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p)
{
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}
bool Procurar_saida(vector<string> &mapa, Pos inicio, Pos fim)
{
    if (inicio.l == fim.l && inicio.c == fim.c)
    {
        mapa[inicio.l][inicio.c] = '.';
        return true;
    }

    if (mapa[inicio.l][inicio.c] != '_')
        return false;

    mapa[inicio.l][inicio.c] = '.';
    show(mapa);
    for (auto vizinho : get_vizinhos(inicio))
    {
        if (Procurar_saida(mapa, vizinho, fim))
            return true;
    }
    mapa[inicio.l][inicio.c] = '_';
    show(mapa);
    return false;
}

int main()
{
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); // começa com nl strings ""
    getchar();                  // remove \n after nc
    Pos inicio, fim;

    // carregando matriz
    ifstream file("labirinto.txt");
    for (int i = 0; i < nl; i++)
    {
        getline(file, mat[i]);
    }

    // procurando inicio e fim e colocando ' ' nas posições iniciais
    for (int l = 0; l < nl; l++)
    {
        for (int c = 0; c < nc; c++)
        {
            if (mat[l][c] == 'I')
            {
                mat[l][c] = '_';
                inicio = Pos{l, c};
            }
            if (mat[l][c] == 'F')
            {
                mat[l][c] = '_';
                fim = Pos{l, c};
            }
        }
    }
    show(mat);

    cout << "       nl=" << nl << " nc=" << nc << "\n";
    cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl;
    Procurar_saida(mat, inicio, fim);
    show(mat);
}