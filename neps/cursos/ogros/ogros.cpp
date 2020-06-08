#include <iostream>
using namespace std;

#define MAXN 100000
#define MAXM 10000

int N, M, A[MAXN], F[MAXN], O[MAXM];

int busca(int x) {
  int ini = 0, fim=N-1, meio, resposta;

  while (ini<=fim) {
    meio = (ini+fim)/2;

    if (A[meio] <= x) {
      ini=meio+1;
      resposta = meio;
    }

    if (A[meio] > x) fim = meio-1;
  }

  return resposta;
}

int main() {
  cin >> N >> M;

  for (int i = 1; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> F[i];
  for (int i = 0; i < M; i++) cin >> O[i];

  for (int i = 0; i < M; i++) {
    cout << F[busca(O[i])] << ' ';
  }

  cout << endl;

  return 0;
}
