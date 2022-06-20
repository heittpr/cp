#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 5*1e4+5;
vector<int> g[maxn];
int n, m, ans, mark[maxn];

void dfs(int u) {
  if (mark[u]) return;
  mark[u] = 1;
  for (int v : g[u]) dfs(v);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  int u, v;
  while (m--) {
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  for (int v = 1; v <= n; v++)
    if (!mark[v]) {
      dfs(v);
      ans++;
    }
  cout << ans << '\n';
}
