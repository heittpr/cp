#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 50010;
vector<int> g[maxn];
int n, dist[maxn], p[maxn], lv[maxn];

void dfs(int v, int l) {
  for (int u : g[v])
    if (u != l) {
      dist[u] = dist[v]+1, p[u] = v;
      dfs(u, v);
    }
}

int dfs2(int v, int l, int x) {
  for (int u : g[v])
    if (u != l) {
      dist[u] = dist[v]+1;
      lv[v] += dfs2(u, v, x);
    }
  if (dist[v] == x) lv[v]++;
  return lv[v];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1, 1);
  int a = 0;
  for (int i = 1; i <= n; i++)
    if (dist[i] > dist[a]) a = i;
  memset(dist, 0, sizeof(dist));
  dfs(a, a);
  int b = 0;
  for (int i = 1; i <= n; i++)
    if (dist[i] > dist[b]) b = i;
  int c, sz = dist[b]+1;
  if (sz % 2 == 0) {
    int c1 = b, c2;
    while (dist[c1] > sz/2)
      c1 = p[c1];
    c2 = p[c1];
    c = n+1, n++;
    for (int i = 0; i < g[c1].size(); i++)
      if (g[c1][i] == c2) {
        g[c1][i] = c;
        break;
      }
    for (int i = 0; i < g[c2].size(); i++)
      if (g[c2][i] == c1) {
        g[c2][i] = c;
        break;
      }
    g[c].pb(c1);
    g[c].pb(c2);
  } else {
    c = b;
    while (dist[c] > sz/2)
      c = p[c];
  }
  memset(dist, 0, sizeof(dist));
  dfs2(c, c, sz/2);
  int t = 0, ans = 0;
  for (int v : g[c])
    t += lv[v];
  for (int v : g[c]) {
    t -= lv[v];
    if (t <= 0) break;
    ans += lv[v]*t;
  }
  cout << sz << '\n' << ans << '\n';
}
