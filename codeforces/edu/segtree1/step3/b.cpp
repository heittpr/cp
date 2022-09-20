#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int n, seg[4*maxn];

void build(int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) {
    if (tl < n) seg[v] = 1;
    return;
  }
  int tm = (tl+tr)/2;
  build(2*v, tl, tm);
  build(2*v+1, tm+1, tr);
  seg[v] = seg[2*v] + seg[2*v+1];
}

void update(int p, int x, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) seg[v] = x;
  else {
    int tm = (tl+tr)/2;
    if (p <= tm) update(p, x, 2*v, tl, tm);
    else update(p, x, 2*v+1, tm+1, tr);
    seg[v] = seg[2*v] + seg[2*v+1];
  }
}

int query(int k, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) return tl;
  int tm = (tl+tr)/2;
  if (seg[2*v+1] > k) return query(k, 2*v+1, tm+1, tr);
  return query(k-seg[2*v+1], 2*v, tl, tm);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n; build();
  vector<int> a(n), ans(n);
  for (int& i : a) cin >> i;
  for (int i = n-1; i >= 0; i--) {
    ans[i] = query(a[i]);
    update(ans[i], 0);
  }
  for (int i : ans) cout << i+1 << ' ';
  cout << '\n';
}
