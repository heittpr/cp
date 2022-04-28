// Febre de Recursões
// https://neps.academy/lesson/176

#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 1000
#define MAXK 1001

long N, K, M, A[MAXN], F[MAXK];

int main() {
  cin >> N >> K >> M;
  for (long i = 1; i <= N; i++) cin >> A[i];
  for (long i = 1; i <= N; i++) cin >> F[i];

  for (long k = N+1; k <= K; k++) {
    for (long i = 1; i <= N; i++)
      F[k] += A[i] * F[k-i];

    F[k] = F[k] % M;
  }

  cout << F[K] << endl;
  return 0;
}
