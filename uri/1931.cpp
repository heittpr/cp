#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e4+5;
const int inf = 1e8+5;
vector<pair<int, int>> g[maxn];
int n, m, dist[maxn][2], mark[maxn][2];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 2; j++)
      dist[i][j] = inf;
  dist[1][0] = 0;
  using iii = tuple<int,int,int>;
  priority_queue<iii, vector<iii>, greater<iii>> q;
  q.push({0, 0, 1});
  while (!q.empty()) {
    auto[d, p, v] = q.top(); q.pop();
    if (mark[v][p]) continue;
    mark[v][p] = 1;
    for (auto[u, w] : g[v])
      if (d+w < dist[u][!p]) {
        dist[u][!p] = d+w;
        q.push({dist[u][!p], !p, u});
      }
  }
  cout << (dist[n][0] != inf ? dist[n][0] : -1) << '\n';
}
