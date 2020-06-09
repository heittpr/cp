// Fechadura
// https://neps.academy/lesson/170

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, resultado;
bool compara(int a, int b) { return a > b; }

int main() {
  cin >> N >> M;
  int pinos[N];

  for (int i = 0; i < N; i++) cin >> pinos[i];

  for (int i = 0; i < N-1; i++) {
    int d = M - pinos[i];

    pinos[i] += d;
    pinos[i+1] += d;

    resultado += abs(d);
  }

  cout << resultado << endl;

  return 0;
}
