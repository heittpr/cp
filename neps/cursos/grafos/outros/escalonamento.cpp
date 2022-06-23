#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 50010;
int n, m, in[maxn];
vector<int> g[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].pb(v);
    in[v]++;
  }
  priority_queue<int> q;
  for (int i = 0; i < n; i++)
    if (in[i] == 0) q.push(-i);
  vector<int> ans;
  while (!q.empty()) {
    int v = q.top(); q.pop();
    ans.pb(-v);
    for (int u : g[-v])
      if (--in[u] == 0)
        q.push(-u);
  }
  if (ans.size() != n) cout << "*\n";
  else for (int i : ans) cout << i << '\n';
}
