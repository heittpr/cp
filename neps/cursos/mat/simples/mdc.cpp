#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, x, ans=0;
  cin >> n; while (n--) {
    cin >> x;
    ans = gcd(ans, x);
  }
  cout << ans << '\n';
}
