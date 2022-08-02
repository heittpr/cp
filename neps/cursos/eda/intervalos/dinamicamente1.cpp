#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bit[(int)(3*1e5+5)];
int n;

ll sum(int k) {
  ll s = 0;
  for (; k >= 1; k -= k&-k)
    s += bit[k];
  return s;
}

void add(int k, int x) {
  for (; k <= n; k += k&-k)
    bit[k] += x;
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
