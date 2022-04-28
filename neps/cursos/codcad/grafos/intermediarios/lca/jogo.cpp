// Jogo da Memória
// https://neps.academy/lesson/219

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;
#define pb push_back
#define endl "\n"
#define maxn 50010
#define maxh 20

int ancestral[maxn][maxh];
int pai[maxn], par[maxn];
int n, h[maxn], c[maxn];
vector<int> adj[maxn];

void dfs(int v) {
  for (int u : adj[v]) {
    if (h[u] == -1) {
      h[u] = h[v]+1;
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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  int tmp;
  for (int i = 1; i <= n; i++) {
    cin >> tmp;

    if(c[tmp]) {
      par[i] = c[tmp];
      par[c[tmp]] = i;
    }

    c[tmp] = i;
  }

  int a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;

    adj[a].pb(b);
    adj[b].pb(a);
  }

  memset(pai, -1, sizeof pai);
  memset(h, -1, sizeof h);
  memset(ancestral, -1, sizeof ancestral);

  h[1] = 0; dfs(1);

  for (int i = 1; i <= n; i++)
    ancestral[i][0] = pai[i];

  for (int j = 1; j < maxh; j++)
    for (int i = 1; i <= n; i++)
      if (ancestral[i][j-1] != -1)
        ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];

  ll res = 0LL;
  for (int i = 1; i <= n; i++)
    res += (ll)(h[i] + h[par[i]] - 2 * h[lca(i, par[i])]);

  cout << res/2 << endl;
}
