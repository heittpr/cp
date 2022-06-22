#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, m, p[510], sz[510];

int find(int v) {
  if (v == p[v]) return v;
  return p[v] = find(p[v]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    if (sz[a] == sz[b]) sz[a] += sz[b];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    p[i] = i, sz[i] = 1;
  vector<tuple<int, int, int>> edges(m);
  for (auto &[w, u, v] : edges)
    cin >> u >> v >> w;
  sort(edges.begin(), edges.end());
  int ans = 0;
  for (auto [w, u, v] : edges)
    if (find(u) != find(v)) {
      merge(u, v);
      ans += w;
    }
  cout << ans << '\n';
}
