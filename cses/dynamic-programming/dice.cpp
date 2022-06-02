#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, dp[(int)1e6+5];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n; dp[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= min(i, 6); j++)
      (dp[i] += dp[i-j]) %= mod;
  cout << dp[n] << '\n';
}
