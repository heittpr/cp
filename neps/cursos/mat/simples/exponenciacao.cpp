#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fexp(ll a, ll  b, ll m) {
  ll ans = 1;
  while (b) {
    if (b&1) (ans*=a) %= m;
    (a*=a) %= m;
    b >>= 1;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll a, b, m; cin >> a >> b >> m;
  cout << fexp(a, b, m) << '\n';
}
