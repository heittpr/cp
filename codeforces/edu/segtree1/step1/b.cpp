#include <bits/stdc++.h>
using namespace std;

struct node {
  int value;
  node(int v = 0) : value(v) {}
  node operator + (node n) {
    return node(min(value, n.value));
  }
};

struct segtree {
  int size;
  vector<node> t;

  void build(vector<int>& a) {
    size = 1;
    while (size < a.size()) size <<= 1;
    t.resize(2*size);
    build(a, 0, 0, size-1);
  }

  void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
      if (tl < a.size()) t[v] = a[tl];
      return;
    }
    int m = (tl+tr)/2;
    build(a, 2*v+1, tl, m);
    build(a, 2*v+2, m+1, tr);
    t[v] = t[2*v+1] + t[2*v+2];
  }

  void update(int p, int x) {
    update(p, x, 0, 0, size-1);
  }

  void update(int p, int x, int v, int tl, int tr) {
    if (tl == tr) t[v] = x;
    else {
      int m = (tl+tr)/2;
      if (p <= m) update(p, x, 2*v+1, tl, m);
      else update(p, x, 2*v+2, m+1, tr);
      t[v] = t[2*v+1] + t[2*v+2];
    }
  }

  int query(int l, int r) {
    return query(l, r, 0, 0, size-1).value;
  }

  node query(int l, int r, int v, int tl, int tr) {
    if (tl > r || tr < l) return node(INT_MAX);
    if (tl >= l && tr <= r) return t[v];
    int m = (tl+tr)/2;
    return query(l, r, 2*v+1, tl, m) + query(l, r, 2*v+2, m+1, tr);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  segtree seg;
  seg.build(a);
  while (m--) {
    int t, x, y; cin >> t >> x >> y;
    if (t == 1) seg.update(x, y);
    else cout << seg.query(x, y-1) << '\n';
  }
}
