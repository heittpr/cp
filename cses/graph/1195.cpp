#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
const int maxn = 1e5+7;
const ll inf = 2*1e14+7;
vector<ii> adjf[maxn], adjr[maxn];
ll dist1[maxn], distn[maxn];
int n, m;

void dijkstra(int x, vector<ii>* adj, ll* dist) {
  vector<bool> seen(n+1, 0);
  priority_queue<pair<ll, int>> q;
  for (int i = 1; i <= n; i++) dist[i] = inf;
  dist[x] = 0; q.push({0, x});
  while (!q.empty()) {
    int v = q.top().second; q.pop();
    if (seen[v]) continue;
    seen[v] = 1;
    for (auto[u, w] : adj[v])
      if (dist[v]+w < dist[u]) {
        dist[u] = dist[v]+w;
        q.push({-dist[u], u});
      }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; int u, v, w;
  while (m--) {
    cin >> u >> v >> w;
    adjf[u].push_back({v, w});
    adjr[v].push_back({u, w});
  }
  dijkstra(1, adjf, dist1);
  dijkstra(n, adjr, distn);
  ll ans = inf;
  for (int v = 1; v <= n; v++)
    for (auto[u, w] : adjf[v])
      ans = min(ans, dist1[v] + (w/2) + distn[u]);
  cout << ans << '\n';
}
