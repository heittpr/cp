#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mult(ll a, ll b, ll m) {
  ll ans = 0;
  while (b) {
    if (b&1) (ans += a) %= m;
    (a <<= 1) %= m;
    b >>= 1;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll a, b, m; cin >> a >> b >> m;
  cout << mult(a, b, m) << '\n';
}
