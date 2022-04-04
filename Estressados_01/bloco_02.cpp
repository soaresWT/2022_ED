#include<iostream>
#include<vector>
#include<stdlib.h> 
#include<random>
#include <cstdlib> 
#include <ctime> 
#include<algorithm>
using namespace std;
//Filter - Operações de Filtragem
std::vector<int> clone(const std::vector<int>& fila)
{
    std::vector<int> clone;
    for (int i = 0; i < fila.size(); i++) {
        clone.push_back(fila[i]);
    }
    return clone;
}
   
vector<int> pegar_homens(const std::vector<int>& fila)
{
    std::vector<int> homens;
    for (int x : fila) {
        if (x > 0) {
            homens.push_back(x);
        }
    }
    return homens;
}
vector<int> pegar_calmos(const std::vector<int>& fila)
{
    std::vector<int> calmos;
    for (int x : fila) {
        if (abs(x) > 0 && abs(x) < 10) {
            calmos.push_back(x);
        }
    }
    return calmos;
}
vector<int> pegar_mulheres_calmas(const std::vector<int>& fila)
{
    std::vector<int> mulher;
    for (int x : fila ) {
        if(x < 0 && x > -10) {
            mulher.push_back(x);
        }
    }
    return mulher;
}
//acesso
vector<int> inverter_com_copia(const std::vector<int>& fila)
{
    std::vector<int> invetido;
    for (int i = fila.size()-1; i >= 0; i--) {
        invetido.push_back(fila[i]);
    }
    return invetido;
}
void inverter_inplace(std::vector<int>& fila)
{   
    int auxiliar = 0;
    int n = fila.size()-1;
    for(int i = 0; i < fila.size()/2; i++){
        auxiliar = fila[i];
        fila[i] = fila[n];
        fila[n] = auxiliar;
        n--;
    }
}
int sortear(const std::vector<int> & vetor)
{
    unsigned seed = time(0);
    srand(seed);
    return vetor[rand()%vetor.size()];
}
void embaralhar(std::vector<int>& vet)
{
    for (int i = 0; i < vet.size(); i++)
	{
        unsigned seed = time(0);
        srand(seed);
		int r = rand() % vet.size();

		int temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
   
}
void ordenar(std::vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            if (v[i] > v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
//conjuntos
vector<int> exclusivos(const std::vector<int>& v)
{
    std::vector<int> exclusivos;
    bool igual = false;
    for (int i = 0; i < v.size(); i++) {
       for (int x : exclusivos) {
           igual = false;
           if( v[i] == x) {
               igual = true;
               break;
           }
       }
       if (igual == false) {
           exclusivos.push_back(v[i]);
       }
    }
    return exclusivos;
}
std::vector<int> diferentes(const std::vector<int>& v)
{
    std::vector<int> inveter;
    for (int p : v) {
        if (p < 0) {
            inveter.push_back(-p);
        } else {
            inveter.push_back(p);
        }
    }

    return  exclusivos(inveter);
}
int main(){
   
}
