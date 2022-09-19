#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, seg[4*maxn];

void build(vector<int>& a, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) {
    if (tl < a.size()) seg[v] = a[tl];
    return;
  }
  int tm = (tl+tr)/2;
  build(a, 2*v, tl, tm);
  build(a, 2*v+1, tm+1, tr);
  seg[v] = max(seg[2*v], seg[2*v+1]);
}

void update(int p, int x, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) seg[v] = x;
  else {
    int tm = (tl+tr)/2;
    if (p <= tm) update(p, x, 2*v, tl, tm);
    else update(p, x, 2*v+1, tm+1, tr);
    seg[v] = max(seg[2*v], seg[2*v+1]);
  }
}

int query(int k, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) return tl;
  int tm = (tl+tr)/2;
  if (seg[2*v] >= k) return query(k, 2*v, tl, tm);
  return query(k, 2*v+1, tm+1, tr);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m; cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  build(a);
  while (m--) {
    int t, i, v, x; cin >> t;
    if (t == 1) {
      cin >> i >> v;
      update(i, v);
    } else {
      cin >> x;
      cout << (seg[1] >= x ? query(x) : -1) << '\n';
    }
  }
}
