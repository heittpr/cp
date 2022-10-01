#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e5+5;
vector<int> g1[maxn], g2[maxn];
int n, m, dist[maxn], p[maxn];

void dfs(vector<int> g[], int v, int l) {
  for (int u : g[v])
    if (u != l) {
      dist[u] = dist[v]+1, p[u] = v;
      dfs(g, u, v);
    }
}

pair<int, int> furthest(vector<int> g[], int s, int v) {
  memset(dist, 0, sizeof(dist));
  memset(p, 0, sizeof(p));
  p[v] = v;
  dfs(g, v, v);
  int mx = 0, f, mid;
  for (int i = 1; i <= s; i++)
    if (dist[i] > mx) {
      mx = dist[i];
      f = i;
    }
  mid = f;
  for (int i = 0; i < (mx+1)/2; i++)
    mid = p[mid];
  return {f, mid};
}

int mid(vector<int> g[], int s) {
  int a = furthest(g, s, 1).first;
  return furthest(g, s, a).second;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g1[u].pb(v);
    g1[v].pb(u);
  }
  for (int i = 1; i < m; i++) {
    int u, v; cin >> u >> v;
    g2[u].pb(v);
    g2[v].pb(u);
  }
  cout << mid(g1, n) << ' ' << mid(g2, m) << '\n';
}
