#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 2*1e5+10;
int n, seg[4*maxn];
vector<int> s;

void build(int v, int l, int r) {
  if (l == r) seg[v] = s[l];
  else {
    int m = (l+r)/2;
    build(2*v, l, m);
    build(2*v+1, m+1, r);
    seg[v] = min(seg[2*v], seg[2*v+1]);
  }
}

void update(int v, int l, int r, int k, int u) {
  if (l == r) seg[v] = u;
  else {
    int m = (l+r)/2;
    if (k <= m) update(2*v, l, m, k, u);
    else update(2*v+1, m+1, r, k, u);
    seg[v] = min(seg[2*v], seg[2*v+1]);
  }
}

int query(int v, int l, int r, int a, int b) {
  if (a > b) return INT_MAX;
  if (a == l && b == r) return seg[v];
  int m = (l+r)/2;
  return min(
    query(2*v, l, m, a, min(b, m)),
    query(2*v+1, m+1, r, max(a, m+1), b) 
  );
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> n >> q; s.resize(n);
  for (int &i : s) cin >> i;
  build(1, 0, n-1);
  int t, a, b;
  while (q--) {
    cin >> t >> a >> b;
    if (t == 1) update(1, 0, n-1, a-1, b);
    else cout << query(1, 0, n-1, a-1, b-1) << '\n';
  }
}
