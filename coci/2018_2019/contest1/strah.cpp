#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int maxn = 2010;
const int inf = 3010;
char grid[maxn][maxn];
int n, m;
ii seg[4*maxn];
ll ans;

ll s[maxn];

void build(vector<int>& a, int v=1, int tl=0, int tr=maxn-1) {
  if (tl == tr) { seg[v] = {a[tl], tl}; return; }
  int tm = (tl+tr)/2;
  build(a, 2*v, tl, tm), build(a, 2*v+1, tm+1, tr);
  seg[v] = min(seg[2*v], seg[2*v+1]);
}

void update(int i, int x, int v=1, int tl=0, int tr=maxn-1) {
  if (tl == tr) { seg[v] = {x, i}; return; }
  int tm = (tl+tr)/2;
  if (i <= tm) update(i, x, 2*v, tl, tm);
  else update(i, x, 2*v+1, tm+1, tr);
  seg[v] = min(seg[2*v], seg[2*v+1]);
}

ii query(int l, int r, int v=1, int tl=0, int tr=maxn-1) {
  if (tl > r || tr < l) return {inf, -1};
  if (tl >= l && tr <= r) return seg[v];
  int tm = (tl+tr)/2;
  return min(query(l, r, 2*v, tl, tm), query(l, r, 2*v+1, tm+1, tr));
}

void solve(int l, int r, int cur) {
  if (l < 1 || r > m || l > r) return;
  auto [mn, idx] = query(l, r);
  ans += ((mn*(mn+1))/2 - (cur*(cur+1))/2) * s[r-l+1];
  solve(l, idx-1, mn), solve(idx+1, r, mn);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> grid[i][j];
  for (int i = 0; i <= 2000; i++)
    for (int j = 0; j <= i; j++)
      s[i] += (j+1)*(i-j);
  vector<int> hist(m+1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      hist[j] = grid[i][j] == '#' ? 0 : hist[j]+1;
    build(hist);
    solve(1, m, 0);
  }
  cout << ans << '\n';
}
