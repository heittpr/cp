#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int n;
ll seg[4*maxn];

void build(vector<int>& a, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) {
    if (tl < a.size()) seg[v] = a[tl];
    return;
  }
  int tm = (tl+tr)/2;
  build(a, 2*v, tl, tm);
  build(a, 2*v+1, tm+1, tr);
  seg[v] = seg[2*v] + seg[2*v+1];
}

void update(int p, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) seg[v] = !seg[v];
  else {
    int tm = (tl+tr)/2;
    if (p <= tm) update(p, 2*v, tl, tm);
    else update(p, 2*v+1, tm+1, tr);
    seg[v] = seg[2*v] + seg[2*v+1];
  }
}

int query(int k, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) return tl;
  int tm = (tl+tr)/2;
  if (seg[2*v] > k) return query(k, 2*v, tl, tm);
  else return query(k-seg[2*v], 2*v+1, tm+1, tr);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m; cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  build(a);
  while (m--) {
    int t, x; cin >> t >> x;
    if (t == 1) update(x);
    else cout << query(x) << '\n';
  }
}
