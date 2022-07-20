#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void Trocar(stack<int> &deposito, stack<int> &prateleira)
{
    while (!deposito.empty())
    {
        prateleira.push(deposito.top());
        deposito.pop();
    }
}

int main()
{
    stack<int> deposito;
    stack<int> prateleira;

    cout << "Digite o numero de produtos a serem colocados no deposito: ";
    int n = 0;
    int comando = 0;
    int elemento = 0;
    cin >> n;
    while (n > 0)
    {
        if (comando = 0)
        {
            cin >> x;
            deposito.push(x);
        }
        if (comando = 1)
            Trocar(deposito, prateleira);

        if (comando = 2)
            cout << prateleira.top() << endl;
    }
    return 0;
}
