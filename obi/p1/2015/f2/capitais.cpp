// Capitais

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
#define pb push_back
#define endl "\n"

#define maxn 100001
#define inf 1000000000

int n, res = inf;
vi adj[maxn];

int dfs(int x, int y) {
  int a = inf, b = inf;
  if (adj[x].size() == 1) a = 0;

  for (int v : adj[x]) {
    if (v == y) continue;
    
    b = min(b, dfs(v,x));
    if (b < a) swap(a, b);
  }

  res = min(res, a + b);
  return a + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  int u, v;
  for (int i = 0; i < n-1; i++) {
    cin >> u >> v;
    
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  dfs(1, 1);
  cout << res << endl;
}
