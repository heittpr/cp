#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

ll sum(int k, vector<ll>& tree) {
  ll s = 0;
  while (k >= 1) {
    s += tree[k];
    k -= k&-k;
  }
  return s;
}

void add(int k, int x, vector<ll>& tree) {
  while (k <= n) {
    tree[k] += x;
    k += k&-k;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  while (cin >> n) {
    ll ans = 0;
    vector<ll> f(n), b1(n+1), b2(n+1);
    for (ll &i : f) cin >> i;
    for (int i=n-1; i >= 0; i--) {
      add(f[i], 1, b1);
      add(f[i], sum(f[i]-1, b1), b2);
      ans += sum(f[i]-1, b2);
    }
    cout << ans << '\n';
  }
}
