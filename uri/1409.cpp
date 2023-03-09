#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf = 1e9+10;
int m, n, g, k, dp[1010];
vector<int> adj[1010];
int c[1010], dist[1010], mark[1010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  while (cin >> m >> n >> g >> k && m != 0) {
    memset(dp, 0x3f, sizeof(dp));
    memset(c, 0, sizeof(c));
    memset(dist, 0, sizeof(dist));
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i <= 1000; i++)
      adj[i].clear();
    vector<int> custo(m), dano(m);
    for (int i = 0; i < m; i++)
      cin >> custo[i] >> dano[i];
    dp[0] = 0;
    for (int i = 1; i <= 1000; i++)
      for (int j = 0; j < m; j++) {
        if (i-dano[j] >= 0) dp[i] = min(dp[i], dp[i-dano[j]]+custo[j]);
        else dp[i] = min(dp[i], custo[j]);
      }
    while (g--) {
      int u, v; cin >> u >> v;
      adj[u].pb(v), adj[v].pb(u);
    }
    while (k--) {
      int i, v; cin >> i >> v;
      c[i] += dp[v];
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i <= 1000; i++) dist[i] = inf;
    dist[1] = c[1];
    q.push({c[1], 1});
    while (!q.empty()) {
      auto[d, v] = q.top(); q.pop();
      if (mark[v]) continue;
      mark[v] = 1;
      for (int u : adj[v]) {
        if (dist[v]+c[u] < dist[u]) {
          dist[u] = dist[v]+c[u];
          q.push({-dist[u], u});
        }
      }
    }
    cout << (dist[n] != inf ? dist[n] : -1) << '\n';
  }
}
