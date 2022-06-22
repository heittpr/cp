#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<pair<int, int>> g[1010];
int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  int ans = 0;
  vector<int> mark(n), mn(n, 1010);
  priority_queue<pair<int, int>> q;
  q.push({0, 0}); mn[0] = 0;
  while (!q.empty()) {
    auto[d, v] = q.top(); q.pop();
    if (mark[v]) continue;
    mark[v] = 1; ans += -d;
    for (auto[u, w] : g[v])
      if (!mark[u] && w < mn[u]) {
        mn[u] = w;
        q.push({-w, u});
      }
  }
  cout << ans << '\n';
}
