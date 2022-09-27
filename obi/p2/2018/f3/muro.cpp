#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long dp[10010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  dp[0] = 1; dp[1] = 1; dp[2] = 5;
  for (int i = 3; i <= n; i++)
    (dp[i] += dp[i-1] + 4*dp[i-2] + 2*dp[i-3]) %= mod;
  cout << dp[n] << '\n';
}
