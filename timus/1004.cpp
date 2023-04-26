#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int inf = 3000010;
int n, m, dist[110], vis[110], p[110];
int adj[110][110], mark[110][110];
vector<ii> g[110];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  while (cin >> n && n != -1) {
    cin >> m;
    memset(mark, 0, sizeof(mark));
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        adj[i][j] = inf;
    while (m--) {
      int u, v, w; cin >> u >> v >> w;
      adj[u][v] = adj[v][u] = min(adj[u][v], w);
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (adj[i][j] != inf && !mark[i][j]) {
          g[i].pb({j, adj[i][j]}), g[j].pb({i, adj[i][j]});
          mark[i][j] = mark[j][i] = 1;
        }
    int best = inf;
    vector<int> ans;
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) dist[i] = inf;
      memset(mark, 0, sizeof(mark));
      memset(vis, 0, sizeof(vis));
      memset(p, 0, sizeof(p));
      priority_queue<array<int, 3>> q;
      q.push({0, k, k});
      dist[k] = 0, p[k] = k;
      while (!q.empty()) {
        auto[d, v, l]  = q.top(); q.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        mark[l][v] = mark[v][l] = 1;
        for (auto[u, w] : g[v])
          if (dist[v]+w < dist[u]) {
            dist[u] = dist[v]+w, p[u] = v;
            q.push({-dist[u], u, v});
          }
      }
      for (int v = 1; v <= n; v++)
        for (int u = v+1; u <= n; u++) {
          if (adj[u][v] != inf && v != k && u != k && !mark[v][u]) {
            int b = adj[v][u]+dist[v]+dist[u];
            if (b < best) {
              vector<int> path, p2;
              int x = v;
              while (x != k) {
                path.pb(x);
                x = p[x];
              }
              path.pb(k);
              x = u;
              while (x != k) {
                p2.pb(x);
                x = p[x];
              }
              reverse(all(p2));
              for (int y : p2) path.pb(y);
              best = b, ans = path;
            }
          }
        }
    }
    if (best == inf) cout << "No solution.\n";
    else {
      for (int i : ans) cout << i << ' ';
      cout << '\n';
    }
  }
}
