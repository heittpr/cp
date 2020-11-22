// Visita entre cidades

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
#define endl "\n"
#define pb push_back
const int maxn = 1e4+1;

int n, a, b;
vector<ii> adj[maxn];
int dist[maxn];
bool seen[maxn];

int dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  priority_queue<ii> q;
  q.push({0, a});
  dist[a] = 0;

  while (!q.empty()) {
    int v = q.top().second;
    q.pop();
    
    if (seen[v]) continue;
    seen[v] = true;

    for (ii n : adj[v]) {
      int d = n.first;
      int u = n.second;

      if (dist[u] > dist[v] + d) {
        dist[u] = dist[v] + d;
        if (u == b) return dist[u];
        q.push({-dist[u], u});
      }
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> a >> b;
  a--, b--;
  
  int p, q, d;
  for (int i = 0; i < n-1; i++) {
    cin >> p >> q >> d;
    p--, q--;
    
    adj[p].pb({d, q});
    adj[q].pb({d, p});
  }
  
  cout << dijkstra() << endl;
}
