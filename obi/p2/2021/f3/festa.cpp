#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<ll> r(m);
  for (ll &i : r) cin >> i;
  vector<ll> f(min(n, 10000));
  iota(f.begin(), f.end(), 1);
  for (int i = m-1; i >= 0; i--) {
    for (ll& j : f) j += (j-1)/(r[i]-1);
    while (f.back() > n) f.pop_back();
  }
  for (int i : f) cout << i << '\n';
}
