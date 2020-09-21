// Copa do Mundo
// https://neps.academy/lesson/216

#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"

struct aresta                  { int peso, x, y; };
bool   cmp(aresta a, aresta b) { return a.peso < b.peso; }

#define MAXN 101
#define MAXA 4951

int     n, f, r;
int     pai[MAXN];
int     peso[MAXN];
aresta  ferrovias[MAXA];
aresta  rodovias[MAXA];

int find(int x) {
  if (pai[x] == x) return x;
  return pai[x] = find(pai[x]);
}

void join(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b) return;
  if (peso[a] > peso[b]) swap(a, b);

  pai[a] = b;
  peso[b] += peso[a];
}

int kruskal(int m, aresta arestas[]) {
  int res = 0;
  
  sort(arestas+1, arestas+m+1, cmp);
  for (int i = 1; i <= m; i++) {
    if (find(arestas[i].x) == find(arestas[i].y)) continue;
    
    join(arestas[i].x, arestas[i].y);
    res += arestas[i].peso;
  }

  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> f >> r;

  for (int i = 1; i <= f; i++)
    cin >> ferrovias[i].x >> ferrovias[i].y >> ferrovias[i].peso;

  for (int i = 1; i <= r; i++)
    cin >> rodovias[i].x >> rodovias[i].y >> rodovias[i].peso;

  for (int i = 1; i <= n; i++)
    pai[i] = i;
   
  int res = 0;
  res += kruskal(f, ferrovias);
  res += kruskal(r, rodovias);

  cout << res << endl;
}
