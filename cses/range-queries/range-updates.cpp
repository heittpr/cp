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
  int q, c=0, d, t, a, b, u, k;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> d;
    add(i, d-c);
    c = d;
  }
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> u;
      add(a, u);
      add(b+1, -u);
    } else {
      cin >> k;
      cout << sum(k) << '\n';
    }
  }
}
