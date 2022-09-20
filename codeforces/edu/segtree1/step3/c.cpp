#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int n, seg[4*2*maxn], first[maxn];

void update(int p, int x, int v=1, int tl=0, int tr=n-1) {
  if (tl == tr) seg[v] = x;
  else {
    int tm = (tl+tr)/2;
    if (p <= tm) update(p, x, 2*v, tl, tm);
    else update(p, x, 2*v+1, tm+1, tr);
    seg[v] = seg[2*v] + seg[2*v+1];
  }
}

int query(int l, int r, int v=1, int tl=0, int tr=n-1) {
  if (tl > r || tr < l) return 0;
  if (tl >= l && tr <= r) return seg[v];
  int tm = (tl+tr)/2;
  return query(l, r, 2*v, tl, tm) + query(l, r, 2*v+1, tm+1, tr);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vector<int> ans(n);
  n *= 2;
  memset(first, -1, sizeof(first));
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (first[x] == -1) first[x] = i;
    else {
      ans[x-1] = query(first[x], i);
      update(first[x], 1);
    }
  }
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}
