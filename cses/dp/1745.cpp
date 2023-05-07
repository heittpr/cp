#include <bits/stdc++.h>
using namespace std;
bool dp[100010];
int n, s, ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vector<int> x(n);
  for (int &i : x) {
    cin >> i;
    s += i;
  }
 
  dp[0] = 1;
  for (int i : x)
    for (int j = s; j >= 0; j--)
      if (dp[j] && !dp[j+i]) {
        dp[j+i] = 1;
        ans++;
      }

  cout << ans << '\n';
  for (int i = 1; i <= s; i++)
    if (dp[i]) cout << i << ' ';
  cout << '\n';
}
