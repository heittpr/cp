#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, t = 0;
  while (cin >> n && n != 0) {
    cout << "Teste " << ++t << '\n';
    map<string, vector<string>> g;
    map<string, int> in;
    for (int i = 0; i < n; i++) {
      string foo; cin >> foo;
    }
    while (n--) {
      string u, v; int m;
      cin >> u >> m;
      while (m--) {
        cin >> v;
        g[u].push_back(v);
        in[v]++;
      }
    }
    queue<string> q;
    for (auto[v, adj] : g)
      if (in[v] == 0) q.push(v);
    vector<string> ans;
    if (q.empty()) cout << "impossivel\n\n";
    else {
      while (!q.empty()) {
        auto v = q.front(); q.pop();
        ans.push_back(v);
        for (auto u : g[v])
          if (--in[u] == 0) q.push(u);
      }
      reverse(ans.begin(), ans.end());
      for (auto s : ans) cout << s << ' ';
      cout << "\n\n";
    }
  }
}
