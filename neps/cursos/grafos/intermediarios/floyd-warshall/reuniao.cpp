// Reunião
// https://neps.academy/lesson/217

#include <iostream>
#include <algorithm>
using namespace std;

#define endl "\n"
#define INF 1000001
#define MAXN 101

int n, m;
int dist[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dist[i][j] = i == j ? 0 : INF;

  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    dist[u][v] = dist[v][u] = min(w, dist[u][v]);
  }

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int res = INF;
  for (int i = 0; i < n; i++) {
    int m = 0;

    for (int j = 0; j < n; j++)
      if (dist[i][j] != INF && i != j)
        m = max(m, dist[i][j]);

    res = min(m, res);
  }

  cout << res << endl;
}
