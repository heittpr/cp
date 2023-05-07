#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, x, dp[1000010];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> x;
  vector<int> c(n);
  for (int &i : c) cin >> i;
  dp[0] = 1;
  for (int i = 1; i <= x; i++)
    for (int j : c) if (j <= i)
        (dp[i] += dp[i-j]) %= mod;
  cout << dp[x] << '\n';
}
