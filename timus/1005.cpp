#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> w(n);
  ll ans = 1e9, sum = 0;
  for (int& i : w) cin >> i, sum += i;
  for (int mask = 0; mask < (1<<n); mask++) {
    ll cur = 0;
    for (int i = 0; i < n; i++)
      if (mask & (1<<i)) cur += w[i];
    ans = min(ans, abs(sum-2*cur));
  }
  cout << ans << '\n';
}
