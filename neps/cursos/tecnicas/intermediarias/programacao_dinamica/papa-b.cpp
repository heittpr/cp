// Trabalho do Papa
// https://neps.academy/lesson/177

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
#define endl "\n"
#define pb push_back
typedef pair<int, int> ii;
#define maxn 1001
#define inf 1000001

bool cmp (ii a, ii b) { return a.second < b.second; }
int n, dp[maxn];
vector<ii> c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  int p, r;
  for (int i = 0; i < n; i++) {
    cin >> p >> r;
    if (r >= p) c.pb({p, r});
  }
  
  n = c.size();
  sort(c.begin(), c.end(), cmp);

  for (int i = 0; i < n; i++) dp[i] = inf;
  
  for (int i = 0; i < n; i++)
    for (int j = i; j >= 0; j--)
      if (dp[j-1] <= c[i].second - c[i].first)
        dp[j] = min(dp[j], dp[j-1] + c[i].first);

  for (int i = n; i >= 0; i--)
    if (dp[i-1] < inf) {
      cout << i << endl;
      return 0;
    }
}
