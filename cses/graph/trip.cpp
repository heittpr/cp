#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n, m, seen[maxn], p[maxn];
vector<int> adj[maxn];

void dfs(int v) {
  seen[v] = 1;
  for (int u : adj[v]) {
    if (u == p[v]) continue;
    if (seen[u]) {
      vector<int> ans = {u};
      while (v != u) {
        ans.push_back(v);
        v = p[v];
      }
      ans.push_back(u);
      cout << ans.size() << '\n';
      for (int a : ans)
        cout << a << ' ';
      cout << '\n';
      exit(0);
    }
    p[u] = v; dfs(u);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; int a, b;
  while (m--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int v = 1; v <= n; v++)
    if (!seen[v]) {
      p[v] = v; dfs(v);
    }
  cout << "IMPOSSIBLE\n";
}
