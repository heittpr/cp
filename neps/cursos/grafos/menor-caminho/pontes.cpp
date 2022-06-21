#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf = 1000010;
vector<pair<int, int>> g[1010];
int n, m, mark[1010], dist[1010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  int u, v, w;
  while (m--) {
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  priority_queue<pair<int, int>> q; q.push({0, 0});
  for (int i = 1; i <= n+1; i++) dist[i] = inf;
  while (!q.empty()) {
    auto[d, v] = q.top(); q.pop();
    mark[v] = 1;
    if (v == n+1) {
      cout << -d << '\n';
      return 0;
    }
    for (auto[u, w] : g[v])
      if (!mark[u] && dist[u] > -d+w) {
        dist[u] = -d+w;
        q.push({-dist[u], u});
      }
  }
}
