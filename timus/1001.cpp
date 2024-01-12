#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<ll> v; ll x;
  while (cin >> x) v.pb(x);
  reverse(v.begin(), v.end());
  cout << setprecision(4) << fixed;
  for (ll a : v)
    cout << sqrt(a) << '\n';
}
