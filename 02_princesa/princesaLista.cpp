#include <iostream>
#include <list>
#include <numeric>

using namespace std;

void show(list<int> &lista, list<int>::iterator &sword)
{
    cout << "[";
    for (auto it = lista.begin(); it != lista.end(); ++it)
    {
        cout << "" << *it;
        if (it == sword)
            cout << ">";
    }
    cout << " ]\n";
}

int main()
{

    int tamanho = 0, espada = 0;
    cin >> tamanho;
    cin >> espada;

    list<int> lista(tamanho);
    iota(begin(lista), end(lista), 1);
    list<int>::iterator it = lista.begin();
    auto sword = next(lista.begin(), espada - 1);
    while (lista.size() > 1)
    {
        show(lista, sword);
        sword++;
        if (sword == lista.end())
            sword = lista.begin();

        sword = lista.erase(sword);

        if (sword == lista.end())
            sword = lista.begin();
    }
    show(lista, sword);
}
