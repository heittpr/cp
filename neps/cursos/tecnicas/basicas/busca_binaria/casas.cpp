// Soma de Casas
// https://neps.academy/lesson/173

#include <iostream>
using namespace std;

#define MAXN 100000
int N, K, casas[MAXN];

int busca(int x) {
  int ini=0, fim=N-1, meio;

  while (ini<=fim) {
    meio = (ini+fim)/2;

    if (casas[meio] > x) fim = meio-1;
    if (casas[meio] < x) ini = meio+1;
    if (casas[meio] == x) return true;
  }

  return false;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> casas[i];
  cin >> K;

  for (int i = 0; i < N; i++) {
    if (busca(K-casas[i])) {
      cout << casas[i] << ' ' << K-casas[i] << endl;
      break;
    }
  }

  return 0;
}
