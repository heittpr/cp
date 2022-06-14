// Bits

#include <iostream>
using namespace std;
#define endl "\n"
const int p = 1e9 + 7;
const int maxn = 1001;

int n, k;
int dp[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  
  dp[0] = 1;
  for (int i = 1; i < k; i++)
    dp[i] = (2*dp[i-1])%p;

  for (int i = k; i <= n; i++)
    for (int j = 1; j <= k; j++)
      dp[i] = (dp[i] + dp[i-j])%p;

  cout << dp[n] << endl;
}
