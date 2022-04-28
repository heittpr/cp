// Caverna de Ordinskaya
// https://neps.academy/lesson/168

#include <iostream>
#include <algorithm>
using namespace std;

long long N, M, resposta, ultimo=0, a;

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> a;
    long long mx = max(a, M-a), mn = M-mx;

    if (mn >= ultimo) {
      resposta += mn;
      ultimo = mn;
    } else if (mx >= ultimo) {
      resposta += mx;
      ultimo = mx;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << resposta << endl;
  return 0;
}
