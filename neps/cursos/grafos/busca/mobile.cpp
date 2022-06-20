#include <bits/stdc++.h>
using namespace std;
vector<int> g[100010];
int n;

int dfs(int u) {
  int sub=1, s, l=-1;
  for (int v : g[u]) {
    s = dfs(v);
    if (l != -1 && l != s) {
      cout << "mal\n";
      exit(0);
    }
    sub += s, l = s;
  }
  return sub;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  int u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> v;
    g[v].push_back(u);
  }
  dfs(0);
  cout << "bem\n";
}
