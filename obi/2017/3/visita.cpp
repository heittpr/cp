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

int dfs(int v, int p, int d) {
  if (v == b) return d;

  for (ii n : adj[v]) {
    int c = n.first;
    int u = n.second;

    if (u != p) {
      int f = dfs(u, v, d+c);
      if (f != -1)
        return f;
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> a >> b;
  
  int p, q, d;
  for (int i = 0; i < n-1; i++) {
    cin >> p >> q >> d;
    
    adj[p].pb({d, q});
    adj[q].pb({d, p});
  }

  cout << dfs(a, a, 0) << endl;
}
