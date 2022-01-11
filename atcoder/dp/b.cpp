#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int n, k, h[maxn], dp[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> h[i];
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
    for (int j = 2; j <= k && i-j >= 1; j++)
      dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
  }
  cout << dp[n] << '\n';
}
