#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n, m, color[maxn];
vector<int> adj[maxn];

void dfs(int v, int c) {
  if (color[v] != 0) return;
  color[v] = c;

  for (int u : adj[v]) {
    if (color[u] == c) {
      cout << "IMPOSSIBLE\n";
      exit(0);
    }
    dfs(u, c == 1 ? 2 : 1);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; int a, b;
  while (m--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int v = 1; v <= n; v++)
    if (color[v] == 0) dfs(v, 1);

  for (int i = 1; i <= n; i++)
    cout << color[i] << ' ';
  cout << '\n';
}
