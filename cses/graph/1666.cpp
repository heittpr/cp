#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
vector<int> adj[maxn];
bool mark[maxn];
int n, m;
vector<int> ans;

void dfs(int v) {
  if (mark[v]) return;
  mark[v] = 1;
  for (int u : adj[v])
    dfs(u);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; int a, b;
  while (m--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  for (int i = 1; i <= n; i++)
    if (!mark[i]) {
      dfs(i);
      ans.push_back(i);
    }

  cout << ans.size()-1 << '\n';
  for (int i = 1; i < ans.size(); i++)
    cout << ans[i-1] << ' ' << ans[i] << '\n';
}
