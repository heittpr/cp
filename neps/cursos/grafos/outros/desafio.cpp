#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
vector<int> g[maxn];
int n, dist[maxn];

void dfs(int v, int p) {
  for (int u : g[v])
    if (u != p) {
      dist[u] = dist[v]+1;
      dfs(u, v);
    }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  int u, mx=-1, ans=0; 
  for (int i = 1; i <= n; i++)
    if (dist[i] > mx) mx=dist[i], u=i;
  dist[u] = 0; dfs(u, u);
  for (int i = 1; i <= n; i++)
    ans = max(ans, dist[i]);
  cout << ans << '\n';
}
