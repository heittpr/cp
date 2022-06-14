// Cápsulas

#include <iostream>
using namespace std;
#define endl "\n"
#define MAXN 100001
#define MAXF 100000001

int n, f;
int c[MAXN];

int moedas(int x) {
  int res = 0;

  for (int i = 0; i < n; i++)
    res += x/c[i];

  return res;
}

int busca(int x) {
  int ini=0, fim=MAXF, meio;

  while (ini < fim) {
    meio = (ini+fim)/2;

    if (moedas(meio) >= x) fim = meio;
    else ini = meio + 1;
  }
  
  return ini;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> f;

  for (int i = 0; i < n; i++)
    cin >> c[i];

  cout << busca(f) << endl;
}
