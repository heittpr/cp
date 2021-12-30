#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const long long inf = 2*1e14+10;
long long dist[maxn];
vector<pair<int, int>> adj[maxn];
bool mark[maxn];
int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; int u, v, w;
  while (m--) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  for (int i = 2; i <= n; i++)
    dist[i] = inf;
  priority_queue<pair<long long, int>> q;
  q.push({0, 1});
  while (!q.empty()) {
    int u = q.top().second; q.pop();
    if (mark[u]) continue;
    mark[u] = 1;
    for (auto[v, w] : adj[u])
      if (dist[u]+w < dist[v]) {
        dist[v] = dist[u]+w;
        q.push({-dist[v], v});
      }
  }
  for (int i = 1; i <= n; i++)
    cout << dist[i] << ' ';
  cout << '\n';
}
