// Reduzindo Detalhes de um Mapa
// https://neps.academy/lesson/210

#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"

struct aresta                   { int peso, x, y; };
bool   cmp(aresta a, aresta b)  { return a.peso < b.peso; }

#define MAXN 501
#define MAXM 124751

int     n, m;
int     pai[MAXN];
int     peso[MAXN];
aresta  arestas[MAXM];

int find(int x) {
  if (pai[x] == x) return x;
  return pai[x] = find(pai[x]);
}

void join(int a, int b) {
  a = find(a);
  b = find(b);

  if (peso[a] < peso[b])
    pai[a] = b;
  else if (peso[b] < peso[a])
    pai[b] = a;
  else {
    pai[a] = b;
    peso[b] ++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  
  for (int i = 1; i <= m; i++)
    cin >> arestas[i].x >> arestas[i].y >> arestas[i].peso;

  for (int i = 1; i <= n; i++)
    pai[i] = i;

  sort(arestas+1, arestas+m+1, cmp);

  int res = 0;
  for (int i = 1; i <= m; i++) {
    if (find(arestas[i].x) != find(arestas[i].y)) {
      join(arestas[i].x, arestas[i].y);
      res += arestas[i].peso;
    }
  }

  cout << res << endl;
}
