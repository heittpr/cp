#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int n, q, bit[maxn];

int sum(int k) {
  int s = 0;
  while (k >= 1) {
    s += bit[k];
    k -= k&-k;
  }
  return s;
}

void add(int k, int x) {
  while (k <= n) {
    bit[k] += x;
    k += k&-k;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q; int a, t, k, p;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    add(i, a);
  }
  while (q--) {
    cin >> t;
    if (t == 0) {
      cin >> k >> p;
      add(k, p-(sum(k)-sum(k-1)));
    } else {
      cin >> k;
      cout << sum(k) << '\n';
    }
  }
}
