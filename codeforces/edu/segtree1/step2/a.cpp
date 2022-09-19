#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int n;

struct node {
  ll m, pref, suf, sum;
  node(ll m, ll pref, ll suf, ll sum) : m(m), pref(pref), suf(suf), sum(sum) {}
  node(int v = 0) {
    m = pref = suf = max(v, 0);
    sum = v;
  }
};
node operator + (node l, node r) {
  return node(
      max({l.m, r.m, l.suf+r.pref}),
      max(l.pref, l.sum+r.pref),
      max(r.suf, r.sum+l.suf),
      r.sum + l.sum
  );
}
node seg[4*maxn];

void build(vector<int>& a, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) {
    if (tl < a.size()) seg[v] = node(a[tl]);
    return;
  }
  int tm = (tl+tr)/2;
  build(a, 2*v, tl, tm);
  build(a, 2*v+1, tm+1, tr);
  seg[v] = seg[2*v] + seg[2*v+1];
}

void update(int p, int x, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) seg[v] = node(x);
  else {
    int tm = (tl+tr)/2;
    if (p <= tm) update(p, x, 2*v, tl, tm);
    else update(p, x, 2*v+1, tm+1, tr);
    seg[v] = seg[2*v] + seg[2*v+1];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m; cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  build(a);
  cout << seg[1].m << '\n';
  while (m--) {
    int i, v; cin >> i >> v;
    update(i, v);
    cout << seg[1].m << '\n';
  }
}
