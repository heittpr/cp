#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 510;
const ll inf = 1e15;
ll dist[maxn][maxn];
int n, m, q;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dist[i][j] = (i == j ? 0 : inf);
  ll u, v, w;
  while (m--) {
    cin >> u >> v >> w;
    dist[u][v] = dist[v][u] = min(w, dist[u][v]);
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  while (q--) {
    cin >> u >> v;
    cout << (dist[u][v] != inf ? dist[u][v] : -1) << '\n';
  }
}
