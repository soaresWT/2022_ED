#include<iostream>
#include<vector>

using namespace std;
//BUSCA
//função 1
bool existe(std::vector<int> vetor, int valor)
{
    for (int x : vetor) {
       if( x == valor) 
        return true;
    }
    return false;
}
//função 2
int contar(std::vector<int> vetor, int valor)
{
    int count = 0;
    for (int x : vetor) {
       if( x == valor) 
        count++;
    }
    return count;
}
//função 3
int procurar_valor(std::vector<int> vetor, int valor)
{
   for (int i = 0; i < vetor.size(); i++) {
       if(vetor[i] == valor){
           return i;
           break;
       }
   }
   return -1;
}
//função 4
int procurar_valor_apos(std::vector<int> vetor, int valor,int Pinicial)
{
    for (int i = Pinicial+1; i < vetor.size(); i++) {
       if(vetor[i] == valor){
           return i;
           break;
       }
   }
   return -1;
}
//MELHOR CASO
//função 1
int procurar_menor(std::vector<int> vetor)
{   
    int menor = vetor[0];
    for (int x : vetor) {
        if (x < menor) {
            menor = x;
        }
    }
    return menor;
}
//função 2
int procurar_menor_pos(std::vector<int> vetor)
{
    int Pmenor = 0;
    for (int i = 0; i < vetor.size(); i++) {
        if(vetor[i]<vetor[Pmenor]){
            Pmenor = i;
        }
    }
    return Pmenor;
}
//função 3
int procurar_menor_apos(std::vector<int> vetor, int Pinicial)
{
    int Pmenor = Pinicial+1;
    for (int i = Pinicial+1; i < vetor.size(); i++) {
        if(vetor[i]<vetor[Pmenor]){
            Pmenor = i;
        }
    }
    return Pmenor;
}
//função 4
int procurar_melhor_se(std::vector<int> vetor)
{
    int PrimeiroH = 0;
    for( int x = 0; x < vetor.size(); x++) {
        if (vetor[x] > 0) {
            PrimeiroH = x;
            break;
        }
    }
    int HmaisCalmo = PrimeiroH;
    for (int i = 0; i < vetor.size(); i++) {
        if (vetor[i] < vetor[HmaisCalmo] && vetor[i] > 0) {
            HmaisCalmo = i;
        }
    }
    return HmaisCalmo;
}
//CONTAGEM
//função 1
float calcular_stress_medio(std::vector<int> fila)
{
   //necessita de atenção
   int soma = 0;
   for (int i = 0; i < fila.size(); i++) {
       if (fila[i]<0) {
           soma += -fila[i];
       } else {
           soma+=fila[i];
       }
   }
   float media = soma/fila.size();
   return media;
}
//função 2
string mais_homens_ou_mulheres(std::vector<int> fila)
{
    int quantMulher = 0;
    int quantHomem = 0;
    for ( int i = 0; i < fila.size(); i++) {
        if (fila[i] < 0) {
            quantMulher++;
        } else {
            quantHomem++;
        }
    }
    if (quantHomem > quantMulher) {
        return "Homens";
    } else if ( quantMulher > quantHomem) {
        return "Mulheres";
    } else {
        return "Empate";
    }
}
//função 3
string qual_metade_eh_mais_estressada(std::vector<int> fila)
{
    float metade = fila.size()/2;

    int primeiraSoma = 0;
    for (int i = 0; i < metade; i++) {
        if (fila[i] < 0) {
            primeiraSoma +=  -fila[i];
        } else {
            primeiraSoma+= fila[i];
        }
    }
    int segundaSoma = 0;
    for (int i = metade; i < fila.size(); i++) {
        if (fila[i] < 0) {
            segundaSoma += -fila[i];
        } else {
            segundaSoma+= fila[i];
        }
    }
    float primeiraMedia = primeiraSoma / metade;
    float segundaMedia = segundaSoma / metade;
    if (primeiraMedia > segundaMedia) {
        return "primeira";
    } else if (segundaMedia > primeiraMedia) {
        return "segunda";
    } else {
        return "empate";
    }
}
bool homens_sao_mais_estressados_que_mulheres(vector<int> fila)
{
    int homens = 0, mulheres = 0;
    for ( auto pessoa : fila) 
       if (pessoa > 0) {
           homens++;
       } else{
           mulheres--;
       }
    
    return (homens > mulheres) ? homens : mulheres;
}
int main(){
    vector<int> fila = {1,2,-3,4,5,-6,7,-8,9,10};
   if(homens_sao_mais_estressados_que_mulheres(fila)){
       cout << "Homens sao mais estressados que mulheres" << endl;
   } else {
       cout << "Mulheres sao mais estressadas que homens" << endl;
   }
    return 0;
}