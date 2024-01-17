#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int maxn = 23;
ll dp[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  dp[0] = 1, dp[1] = k-1;
  for (int i = 1; i <= n; i++)
    dp[i] = (k-1)*(dp[i-1] + dp[i-2]);
  cout << dp[n] << '\n';
}
