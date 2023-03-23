#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6+5;
int dp[inf];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    for (int i = 0; i <= m; i++) dp[i] = inf;
    dp[0] = 0;
    for (int i : a)
      for (int j = 0; j <= m; j++) 
        if (i <= j) dp[j] = min(dp[j], dp[j-i]+1);
    cout << dp[m] << '\n';
  }
}
