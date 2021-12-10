#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+10;
int n, tree[1<<(__lg(maxn)+2)];

void update(int k, int x) {
  k += n; tree[k] = x;
  for (k >>= 1; k >= 1; k >>= 1)
    tree[k] = max(tree[2*k], tree[2*k+1]);
}

int query(int x) {
  if (tree[1] < x) return 0;
  int k = 1;
  while (k < n) {
    if (tree[2*k] >= x) k = 2*k;
    else k = 2*k+1;
  }
  update(k-n, tree[k]-x);
  return k-n;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int m, b, r; cin >> n >> m;

  b = n; n = 1<<(__lg(n-1)+1);
  for (int i = 1; i <= b; i++)
    cin >> tree[i+n];
  for (int i = n-1; i >= 1; i--)
    tree[i] = max(tree[2*i], tree[2*i+1]);

  while (m--) {
    cin >> r;
    cout << query(r) << '\n';
  }
}
