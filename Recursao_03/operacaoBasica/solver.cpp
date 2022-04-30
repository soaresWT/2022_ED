#include <sstream>  //stringstream
#include <iostream> //cout
#include <vector>   //vector
using namespace std;

int sum(std::vector<int> v)
{
    return (v.size() == 1) ? v[0] : v[0] + sum(std::vector<int>(v.begin() + 1, v.end()));
}

void print(std::vector<int> v)
{
    if (v.size() == 1)
        cout << v[0] << endl;

    cout << v[0] << " ";
    print(std::vector<int>(v.begin() + 1, v.end()));
}
// print all elements vector in reverse order using recursion
void printReverse(std::vector<int> v, int n)
{
    if (n == 0)
        return;

    cout << v[n - 1] << " ";
    printReverse(v, n - 1);
}
// multiplication elements vector using recursion
int multiplication(std::vector<int> v, int n)
{
    return (n == 0) ? 1 : v[n - 1] * multiplication(v, n - 1);
}
// minimum element in vector using recursion
int minimum(std::vector<int> v, int n, int min)
{
    if (n == 0)
        return min;

    if (v[n - 1] < min)
        min = v[n - 1];

    return minimum(v, n - 1, min);
}
// inverte elements in vector using recursion and print vector
void reverse(std::vector<int> &vet, int pos = 0)
{
    if (pos >= vet.size() / 2)
        return;

    std::swap(vet[pos], vet[vet.size() - 1 - pos]);
    reverse(vet, pos + 1);
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while (ss >> value)
        vet.push_back(value);
    // cout << sum(vet) << endl;
    // print(vet);
    // printReverse(vet, vet.size());
    // cout << multiplication(vet, vet.size()) << endl;
    // cout << minimum(vet, vet.size(), vet[0]) << endl;
    reverse(vet);
    print(vet);
}