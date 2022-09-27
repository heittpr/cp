#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n;

struct node {
  int min1, min2, max1, max2;
  int imin1, imin2, imax1, imax2;

  node(int v = 0, int p = 0) {
    min1 = min2 = INT_MAX, max1 = max2 = INT_MIN;
    imin1 = imin2 = imax1 = imax2 = 0;
    if (v) {
      min1 = max1 = v;
      imin1 = imax1 = p;
    }
  }

  void add(int v, int p) {
    if (v < min1) min1 = v, imin1 = p;
    if (v > max1) max1 = v, imax1 = p;
  }

  int ans() {
    if (imin1 == imax1) return max(max1-min2, max2-min1);
    else return max1-min1;
  }
};
node operator + (node l, node r) {
  node s;
  vector<pair<int, int>> v = {{l.min1, l.imin1}, {l.min2, l.imin2}, {r.min1, r.imin1}, {r.min2, r.imin2}};
  sort(v.begin(), v.end());
  s.min1 = v[0].first, s.imin1 = v[0].second;
  for (int i = 1; i < 4; i++)
    if (v[i].second != s.imin1) {
      s.min2 = v[i].first, s.imin2 = v[i].second;
      break;
    }
  vector<pair<int, int>> w = {{l.max1, l.imax1}, {l.max2, l.imax2}, {r.max1, r.imax1}, {r.max2, r.imax2}};
  sort(w.begin(), w.end(), greater<pair<int, int>>());
  s.max1 = w[0].first, s.imax1 = w[0].second;
  for (int i = 1; i < 4; i++)
    if (w[i].second != s.imax1) {
      s.max2 = w[i].first, s.imax2 = w[i].second;
      break;
    }
  return s;
}
node seg[4*maxn];

void build(vector<int>& a, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) {
    if (tl < a.size()) seg[v] = node(a[tl], tl);
    return;
  }
  int tm = (tl+tr)/2;
  build(a, 2*v, tl, tm);
  build(a, 2*v+1, tm+1, tr);
  seg[v] = seg[2*v] + seg[2*v+1];
}

void update(int p, int x, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) seg[v].add(x, p);
  else {
    int tm = (tl+tr)/2;
    if (p <= tm) update(p, x, 2*v, tl, tm);
    else update(p, x, 2*v+1, tm+1, tr);
    seg[v] = seg[2*v] + seg[2*v+1];
  }
}

node query(int l, int r, int v=1, int tl=0, int tr=n-1) {
  if (tl > r || tr < l) return node();
  if (tl >= l && tr <= r) return seg[v];
  int tm = (tl+tr)/2;
  return query(l, r, 2*v, tl, tm) + query(l, r, 2*v+1, tm+1, tr);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m; cin >> n >> m;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  build(a);
  while (m--) { 
    int t, x, y; cin >> t >> x >> y;
    if (t == 1) update(y-1, x);
    else cout << query(x-1, y-1).ans() << '\n';
  }
}
