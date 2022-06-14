// Linhas de Ônibus

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define endl "\n"
#define pb push_back
#define maxn 1010

int t, l, o, d, dist[maxn];
vector<int> adj[maxn];

int bfs(int v) {
  memset(dist, -1, sizeof dist);
  queue<int> q;
  q.push(v);
  dist[v] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int n : adj[u])
      if (dist[n] == -1) {
        dist[n] = dist[u] + 1;
        if (n == d) return dist[n];
        q.push(n);
      }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> t >> l >> o >> d;
  
  int c, k;
  for (int i = 1; i <= l; i++) {
    cin >> c;
    
    while(c--) {
      cin >> k;

      adj[k].pb(t+i);
      adj[t+i].pb(k);
    }
  }

  cout << bfs(o)/2 << endl;
}
