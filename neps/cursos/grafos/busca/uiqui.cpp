#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  unordered_map<string, unordered_set<string>> g;
  set<string> p;
  string a, b;
  while (n--) {
    cin >> a >> b;
    g[a].insert(b);
    p.insert(a); p.insert(b);
  }
  string last;
  for (auto s : p) {
    if (!last.empty()) {
      g[s].insert(last);
      g[last].insert(s);
    }
    last = s;
  }
  cin >> a >> b;
  queue<string> q({a});
  map<string, int> dist;
  while (!q.empty()) {
    string v = q.front(); q.pop();
    if (v == b) {
      cout << dist[v] << '\n';
      return 0;
    }
    for (auto u : g[v]) {
      if (!dist.count(u)) {
        dist[u] = dist[v]+1;
        q.push(u);
      }
    }
  }
}
