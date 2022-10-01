#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 2e5+5;
int n, pos[maxn], mark[4*maxn];
vector<int> g[4*maxn];
vector<tuple<int, int, int>> planos;

void build(int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) {
    if (tl < n) pos[tl] = v;
    return;
  }
  int tm = (tl+tr)/2;
  build(2*v, tl, tm);
  build(2*v+1, tm+1, tr);
  g[v].pb(2*v);
  g[v].pb(2*v+1);
}

void add(int u, int l, int r, int v=1, int tl=0, int tr=n-1) {
  if (tl > r || tr < l) return;
  if (tl >= l && tr <= r) {
    g[pos[u]].pb(v);
    return;
  }
  int tm = (tl+tr)/2;
  add(u, l, r, 2*v, tl, tm);
  add(u, l, r, 2*v+1, tm+1, tr);
}

bool dfs(int v) {
  mark[v] = 1;
  for (int u : g[v]) {
    if (mark[u] == 1) return true;
    if (mark[u] == 0 && dfs(u)) return true;
  }
  mark[v] = 2;
  return false;
}

bool ok(int x) {
  memset(mark, 0, sizeof(mark));
  for (int i = 0; i < n; i++)
    g[pos[i]].clear();
  for (int i = 0; i < x; i++) {
    auto[u, l, r] = planos[i];
    add(u-1, l-1, r-1);
  }
  for (int i = 0; i < n; i++)
    if (!mark[pos[i]] && dfs(pos[i]))
      return true;
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m; cin >> n >> m;
  build();
  planos.resize(m);
  for (auto&[u, l, r] : planos)
    cin >> u >> l >> r;
  int l = 1, r = m, ans = -1;
  while (l <= r) {
    int mid = (l+r)/2;
    if (ok(mid)) ans=mid, r=mid-1;
    else l = mid+1;
  }
  cout << ans << '\n';
}
