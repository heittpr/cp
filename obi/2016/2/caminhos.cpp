// Caminhos do Reino

#include <algorithm>
#include <iostream>
#include <cstring>


using namespace std;
#define endl "\n"
#define maxn 100001

int n, q, t;
int h[maxn], raiz[maxn];
int adj[maxn], in[maxn];
bool c[maxn];

void dfs(int x) {
  if (!c[x]) {
    dfs(adj[x]);
    h[x] = h[adj[x]] + 1;
    raiz[x] = raiz[adj[x]];
  }
}

int dist(int a, int b) {
  if (h[a] < h[b]) swap(a,b);

  if (raiz[a] == raiz[b])
    return h[a] - h[b];

  return min(
    max(h[a], h[b] + ((raiz[a] - raiz[b] + t)%t)),
    max(h[b], h[a] + ((raiz[b] - raiz[a] + t)%t))
  );
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> adj[i];
    in[adj[i]]++;
  }

  for (int i = 1; i <= n; i++)
    if (in[i] >= 2) {
      while (!c[i]) {
        c[i] = true;
        raiz[i] = t++;
        i = adj[i];
      }

      break;
    }

  for (int i = 1; i <= n; i++)
    if (!in[i])
      dfs(i);

  cin >> q;

  int a, b;
  while (q--) {
    cin >> a >> b;
    cout << dist(a, b) << endl;
  }
}
