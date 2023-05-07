#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll n, t=0; cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
    t += v[i];
  }
  
  sort(v.begin(), v.end());
  ll m = v[v.size()/2];
  ll ans = 0;
  for (ll i : v)
    ans += abs(i-m);

  cout << ans << '\n';
}
