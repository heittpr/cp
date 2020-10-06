// Jogo da Memória
// https://neps.academy/lesson/219

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef vector<int> vi;
#define endl "\n"
#define pb push_back
#define MAXN 50002
#define MAXL 16

int n, c[MAXN], par[MAXN];
int pai[MAXN],  lvl[MAXN];
int ancestral[MAXN][MAXL];
vi adj[MAXN];

void dfs(int u) {
  for (int v : adj[u]) {
    if (lvl[v] == -1) {
      lvl[v] = lvl[u] + 1;
      pai[v] = u;

      dfs(v);
    }
  }
}

int lca(int u, int v) {
  if (lvl[u] < lvl[v]) swap(u, v);

  for (int i = MAXL-1; i >= 0; i--)
    if (lvl[u] - (1<<i) >= lvl[v])
      u = ancestral[u][i];

  if (u == v) return u;

  for (int i = MAXL-1; i >= 0; i--)
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

    if (c[tmp]) {
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

  memset(lvl, -1, sizeof lvl);
  memset(pai, -1, sizeof pai);
  memset(ancestral, -1, sizeof ancestral);

  lvl[1] = 0;
  dfs(1);

  for (int i = 1; i <= n; i++)
    ancestral[i][0] = pai[i];

  for (int j = 1; j < MAXL; j++)
    for (int i = 1; i <= n; i++)
      if (ancestral[i][j-1] != -1)
        ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];

  long long res = 0LL;

  for(int i = 1;i <= n;i++)
    res += (long long)(lvl[i] + lvl[par[i]] - 2*lvl[lca(i, par[i])]);

  cout << res/2 << endl;
}
