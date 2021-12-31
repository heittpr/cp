#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2510;
const ll inf = -5*1e12-10;
vector<tuple<int, int, int>> edges;
vector<int> adjr[maxn];
int n, m, mark[maxn], seen[maxn];
ll dist[maxn];

void dfs(int v) {
  if (mark[v]) {
    cout << "-1\n";
    exit(0);
  }
  if (seen[v]) return;
  seen[v] = 1;
  for (int u : adjr[v]) dfs(u);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; int u, v, w;
  while (m--) {
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
    adjr[v].push_back(u);
  }
  for (int i = 2; i <= n; i++)
    dist[i] = inf;
  for (int i = 1; i <= n; i++)
    for (auto[u, v, w] : edges)
      if (dist[u] != inf && dist[v] < dist[u]+w) {
        dist[v] = dist[u]+w;
        if (i == n) mark[v] = 1;
      }
  dfs(n);
  cout << dist[n] << '\n';
}
