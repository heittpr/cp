#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2*1e5+10;
ll tree[maxn];
int n;

void add(int k, int x) {
  while (k <= n) {
    tree[k] += x;
    k += k&-k;
  }
}

ll sum(int k) {
  ll s = 0;
  while (k >= 1) {
    s += tree[k];
    k -= k&-k;
  }
  return s;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q, x; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    add(i, x);
  }
  int t, a, b;
  while (q--) {
    cin >> t >> a >> b;
    if (t == 1) add(a, b-(sum(a)-sum(a-1)));
    else cout << sum(b)-sum(a-1) << '\n';
  }
}
