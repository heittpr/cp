#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll q, k, c, d, s, t, i, j, m, n, ans;
  cin >> q;
  while (q--) {
    cin >> k;
    d=0, t=0, i=9;

    while (t < k) {
      s = t;
      t += i*++d;
      i *= 10;
    }

    c = d; m = 1;
    while (--c) m *= 10; m--;

    n = m + (k-s-1)/d+1;
    j = d-((k-s-1)%d);

    while (j--) {
      ans = n%10;
      n /= 10;
    }

    cout << ans << '\n';
  }
}
