#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6+5;
int n, x, dp[inf];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> x; vector<int> c(n);
  for (int &i : c) cin >> i;
  for (int i = 1; i <= x; i++) {
    dp[i] = inf;
    for (int j : c) if (j <= i)
      dp[i] = min(dp[i], dp[i-j]+1);
  }
  cout << (dp[x] != inf ? dp[x] : -1) << '\n';
}
