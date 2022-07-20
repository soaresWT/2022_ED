#include <iostream>
#include <algorithm>
#include <vector>

struct Posicao
{
    int linha, coluna;

    Posicao(int linha, int coluna)
    {
        this->linha = linha;
        this->coluna = coluna;
    }
};

void show(std::vector<std::string> &mat)
{
    for (auto element : mat)
        std::cout << element << std::endl;
}

std::vector<Posicao> Getvizinhos(const Posicao &pos)
{
    auto l_pos = pos.linha;
    auto c_pos = pos.coluna;

    return {{l_pos, c_pos - 1}, {l_pos + 1, c_pos}, {l_pos, c_pos + 1}, {l_pos - 1, c_pos}};
}

bool PodeFurar(std::vector<std::string> &lab, Posicao &pos)
{
    int count = 0;
    auto aux = Getvizinhos(pos);

    if (lab[pos.linha][pos.coluna] == ' ')
        return false;

    for (auto [l, c] : aux)
    {
        if (l >= int(lab.size()) || c >= int(lab[0].size()) || l < 0 || c < 0)
            continue;

        if (lab[l][c] == '#')
            count++;
    }

    if (count >= 3)
        return true;

    return false;
}

void DerrubarParede(std::vector<std::string> &lab, Posicao &pos)
{
    int nl = lab.size();
    int nc = lab[0].size();
    auto l = pos.linha;
    auto c = pos.coluna;

    if (l >= nl - 1 || c >= nc - 1 || l < 1 || c < 1)
        return;

    if (PodeFurar(lab, pos))
    {
        lab[l][c] = ' ';
        auto vizinhos = Getvizinhos(pos);
        std::random_shuffle(vizinhos.begin(), vizinhos.end());

        for (auto vizinho : vizinhos)
            DerrubarParede(lab, vizinho);
    }
}

Posicao iniciar(std::vector<std::string> &lab)
{
    int l_pos = std::rand() % (lab.size() - 2) + 1;
    int c_pos = std::rand() % (lab[0].size() - 2) + 1;

    return {l_pos, c_pos};
}

int main(int argc, char *argv[])
{
    int nl{}, nc{};

    if (argc > 2)
    {
        nl = std::atoi(argv[1]);
        nc = std::atoi(argv[2]);
    }

    std::vector<std::string> labirinto(nl, std::string(nc, '#'));

    auto inicio = iniciar(labirinto);

    DerrubarParede(labirinto, inicio);
    show(labirinto);

    return 0;
}

// g++ -std=c++17 -o solver solver.cpp