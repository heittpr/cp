#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 1e9+7;
const int maxn = 1e6+10;
ll dp[maxn][2];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t, n, m=2; cin >> t;
  dp[1][0] = 1;
  dp[1][1] = 1;

  while (t--) {
    cin >> n;

    for (int i = m; i <= n; i++) {
      dp[i][0] = (4*dp[i-1][0] + dp[i-1][1]) % p;
      dp[i][1] = (2*dp[i-1][1] + dp[i-1][0]) % p;
    }
    
    m = max(m, n);
    cout << (dp[n][0] + dp[n][1]) % p << '\n';
  }
}
