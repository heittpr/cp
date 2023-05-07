#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6+5;
int n, dp[inf];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dp[i] = inf;
    for (int x = i; x; x /= 10)
      dp[i] = min(dp[i], dp[i-(x%10)]+1);
  }
  cout << dp[n] << '\n';
}
