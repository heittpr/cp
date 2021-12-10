#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+10;
int n, m, p, seg[1<<(__lg(maxn)+2)];

void update(int k) {
  k += n; seg[k] = 0;
  for (k >>= 1; k >= 1; k >>=1)
    seg[k] = seg[2*k] + seg[2*k+1];
}

int query(int x) {
  int k = 1;
  while (k < n) {
    if (seg[2*k] < x) {
      x -= seg[2*k];
      k = 2*k+1;
    } else k *= 2;
  }
  return k-n;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n; vector<int> x(n);
  for (int &i : x) cin >> i;

  m = n; n = 1<<(__lg(n-1)+1);
  for (int i = n; i < 2*n; i++)
    seg[i] = 1;
  for (int i = n-1; i >= 1; i--)
    seg[i] = seg[2*i] + seg[2*i+1];

  while (m--) {
    cin >> p; p = query(p);
    cout << x[p] << '\n';
    update(p);
  }
}
