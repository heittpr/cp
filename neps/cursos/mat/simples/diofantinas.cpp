#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b, ll& x, ll& y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  ll x1, y1;
  ll d = gcd(b%a, a, x1, y1);
  x = y1 - (b/a)*x1;
  y = x1;
  return d;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll a, b, c; cin >> a >> b >> c;
  if (a == 0 || b == 0) {
    if (c == 0) cout << "1\n0 0\n";
    else cout << "-1\n";
    return 0;
  }
  ll x, y;
  ll g = gcd(abs(a), abs(b), x, y);
  if (a < 0) x = -x;
  if (b < 0) y = -y;
  if (c%g != 0) cout << "-1\n";
  else cout << "1\n" << x*(c/g) << ' ' << y*(c/g) << '\n';
}
