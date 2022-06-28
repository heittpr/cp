#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, m; cin >> n >> m;
  for (ll i = m; i >= 1; i--)
    if (gcd(i, n) == 1) {
      cout << i << '\n';
      return 0;
    }
}
