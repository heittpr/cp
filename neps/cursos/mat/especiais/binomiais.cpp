#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k, m; cin >> n >> k >> m;
  if (n < k) cout << "0\n";
  else {
    vector<long long> fact(n+1), inv(n+1), invfact(n+1);
    fact[0] = fact[1] = invfact[0] = invfact[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
      inv[i] = m + (-(m/i) * inv[m%i] % m);
      fact[i] = (i*fact[i-1])%m;
      invfact[i] = (inv[i]*invfact[i-1])%m;
    }
    cout << (((fact[n]*invfact[k])%m)*invfact[n-k])%m << '\n';
  }
}
