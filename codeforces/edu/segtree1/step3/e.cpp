#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int n;
ll seg[4*maxn];

void update(int p, int x, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) seg[v] += x;
  else {
    int tm = (tl+tr)/2;
    if (p <= tm) update(p, x, 2*v, tl, tm);
    else update(p, x, 2*v+1, tm+1, tr);
    seg[v] = seg[2*v] + seg[2*v+1];
  }
}

ll query(int l, int r, int v=1, int tl=0, int tr=n-1) {
  if (tl > r || tr < l) return 0;
  if (tl >= l && tr <= r) return seg[v];
  int tm = (tl+tr)/2;
  return query(l, r, 2*v, tl, tm) + query(l, r, 2*v+1, tm+1, tr);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m; cin >> n >> m; n+=2;
  while (m--) {
    int t; cin >> t;
    if (t == 1) {
      int l, r, v; cin >> l >> r >> v;
      update(l, v);
      update(r, -v);
    } else {
      int i; cin >> i;
      cout << query(0, i) << '\n';
    }
  }
}
