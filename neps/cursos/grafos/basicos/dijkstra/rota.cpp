// Desvio de Rota
// https://neps.academy/lesson/214

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define endl "\n"
#define pb push_back
#define INF 62250
#define MAXN 251

int n, m, c, k;
int dist[MAXN];
bool seen[MAXN];
vii grafo[MAXN];

void dijkstra(int x) {
  priority_queue<ii> q;

  for (int i = 0; i <= n+1; i++)
    dist[i] = INF;

  dist[x] = 0;
  q.push({0, x});

  while (!q.empty()) {
    int u = q.top().second;
    q.pop();

    if (seen[u]) continue;
    seen[u] = true;

    for (ii vizinho : grafo[u]) {
      int custo = vizinho.first;
      int v = vizinho.second;

      if (u < c && v != u+1) continue;

      if (dist[v] > dist[u] + custo) {
        dist[v] = dist[u] + custo;
        q.push({-dist[v], v});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> c >> k;

  while(n != 0) {
    int u, v, p;
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> p;
      grafo[u].pb({p, v});
      grafo[v].pb({p, u});
    }

    dijkstra(k);
    cout << dist[c-1] << endl;

    for (int i = 0; i <= n+1; i++) {
      grafo[i].clear();
      seen[i] = false;
    }

    cin >> n >> m >> c >> k;
  }
}
