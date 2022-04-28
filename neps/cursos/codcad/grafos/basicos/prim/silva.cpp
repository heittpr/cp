// Frete da Família Silva
// https://neps.academy/lesson/211

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define endl "\n"
#define pb push_back
#define INF 10000001
#define MAXN 1001

int n, m;
int dist[MAXN];
bool seen[MAXN];
vii adj[MAXN];

int prim() {
  priority_queue<ii> q;

  for (int i = 0; i < n; i++)
    dist[i] = INF;

  dist[0] = 0;
  q.push({0, 0});

  while (!q.empty()) {
    int u = q.top().second; q.pop();

    if (seen[u]) continue;
    seen[u] = true;

    for (ii n : adj[u]) {
      int w = n.first, v = n.second;

      if (w < dist[v] && !seen[v]) {
        dist[v] = w;
        q.push({-w, v});
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += dist[i];

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;

  int p, q, u;
  for (int i = 0; i < m; i++) {
    cin >> p >> q >> u;
    adj[p].pb({u, q});
    adj[q].pb({u, p});
  }

  cout << prim() << endl;
}
