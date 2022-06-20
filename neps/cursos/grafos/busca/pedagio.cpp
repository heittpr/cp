#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int c, e, l, p, t=0;
  while (cin >> c >> e >> l >> p && c != 0) {
    int u, v;
    vector<vector<int>> g(c+1);
    while (e--) {
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    queue<pair<int, int>> q({{l,0}});
    vector<bool> mark(c+1);
    vector<int> ans;
    while (!q.empty()) {
      auto[v,d] = q.front(); q.pop();
      if (mark[v] || d > p) continue;
      mark[v] = 1;
      if (v != l) ans.push_back(v);
      for (int u : g[v])
        q.push({u, d+1});
    }
    sort(ans.begin(), ans.end());
    cout << "Teste " << ++t << '\n';
    for (int i : ans) cout << i << ' ';
    cout << "\n\n";
  }
}
