#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> dp(n+1, 1e6+5); dp[0] = 0;
  for (int i=1; i <= n; i++)
    for (int x = i; x; x /= 10)
      dp[i] = min(dp[i], dp[i-(x%10)]+1);
  cout << dp[n] << '\n';
}
