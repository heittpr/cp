// Dona Formiga

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
#define endl "\n"
#define pb push_back
#define maxs 210
#define maxt 19910

int s, t, p, h[maxs], dp[maxs];
vector<int> adj[maxt];

int dfs(int v) {
  if (dp[v] != -1) return dp[v];
  int res = 0;

  for (int u : adj[v])
    if (h[u] < h[v])
      res = max(res, 1+dfs(u));

  return dp[v] = res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> s >> t >> p;
  for (int i = 1; i <= s; i++)
    cin >> h[i];
  
  int i, j;
  for (int h = 0; h < t; h++) {
    cin >> i >> j;

    adj[i].pb(j);
    adj[j].pb(i);
  }

  memset(dp, -1, sizeof dp);
  cout << dfs(p) << endl;
}
