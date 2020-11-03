// Colônia de Formigas
// https://neps.academy/lesson/220

#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

#define pb push_back
#define endl "\n"
#define maxn 100100
#define maxh 20

int n, q, h[maxn], pai[maxn];
int ancestral[maxn][maxh];
vector<ii> adj[maxn];
ll d[maxn];

void dfs(int v) {
  for (ii e : adj[v]) {
    int u = e.first;

    if (h[u] == -1) {
      d[u] = d[v] + e.second;
      h[u] = h[v] + 1;
      pai[u] = v;

      dfs(u);
    }
  }
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);

  for (int i = maxh-1; i >= 0; i--)
    if (h[u] - (1<<i) >= h[v])
      u = ancestral[u][i];

  if (u == v) return u;

  for (int i = maxh-1; i >= 0; i--)
    if (ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]) {
      u = ancestral[u][i];
      v = ancestral[v][i];
    }

  return pai[u];
}

ll dist(int a, int b) { return d[a] + d[b] - 2 * d[lca(a, b)]; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  while (n != 0) {
    memset(d, 0, sizeof d);
    memset(h, -1, sizeof h);
    memset(pai, -1, sizeof pai);
    memset(ancestral, -1, sizeof ancestral);
    for (int i = 0; i < n; i++) adj[i].clear();

    int a, l;
    for (int i = 1; i < n; i++) {
      cin >> a >> l;

      adj[i].pb({a, l});
      adj[a].pb({i, l});
    }
 
    pai[0] = h[0] = 0; dfs(0);

    for (int i = 0; i < n; i++)
      ancestral[i][0] = pai[i];

    for (int j = 1; j < maxh; j++)
      for (int i = 0; i < n; i++)
        if (ancestral[i][j-1] != -1)
          ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
    
    cin >> q;
    int s, t;

    while (q--) {
      cin >> s >> t;
      cout << dist(s, t) << " ";
    }

    cout << endl;
    cin >> n;
  }
}
