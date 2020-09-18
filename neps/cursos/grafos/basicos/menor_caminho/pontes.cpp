// Caminho das Pontes
// https://neps.academy/lesson/212

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define pb push_back
#define endl "\n"
#define INF 20010
#define MAXN 1010

int n, m;
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

  cin >> n >> m;

  int s, t, b;
  for (int i = 0; i < m; i++) {
    cin >> s >> t >> b;
    grafo[s].pb({b, t});
    grafo[t].pb({b, s});
  }

  dijkstra(0);
  cout << dist[n+1] << endl;
}
