#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int seen[maxn], last[maxn];
vector<int> adj[maxn];
int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; int a, b;
  while (m--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> q;
  q.push(1); seen[1] = 1;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u : adj[v]) {
      if (seen[u]) continue;
      seen[u] = 1;
      last[u] = v;
      q.push(u);
    }
  }

  if (!seen[n]) cout << "IMPOSSIBLE\n";
  else {
    vector<int> path;
    while (n != 0) {
      path.push_back(n);
      n = last[n];
    }
    cout << path.size() << '\n';
    for (int i = path.size()-1; i >= 0; i--)
      cout << path[i] << ' ';
    cout << '\n';
  }
}
