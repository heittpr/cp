// Troco Fácil
// https://neps.academy/lesson/171

#include <iostream>
using namespace std;

int moedas[6] = { 100, 50, 25, 10, 5, 1 };
int N, resposta;

int main() {
  cin >> N;

  for ( int moeda : moedas ) {
    resposta += N / moeda;
    N = N % moeda;

    if ( N == 0 ) break;
  }
  
  cout << resposta << endl;
  return 0;
}
