// Castelos da Nlogônia

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef vector<int> vi;
#define endl "\n"
#define pb push_back
#define maxn 101

int n, m, q, c;
int  cor[maxn];
vi   adj[maxn];
bool seen[maxn];

bool dfs(int x) {
  if (seen[x]) return false;
  seen[x] = true;

  if (x == q) {
    cor[x] = c;
    return true;
  }

  for (int v : adj[x])
    if (dfs(v)) {
      cor[x] = c;
      return true;
    }

  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int u, v;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  int p;
  while (m--) {
    memset(seen, false, sizeof seen);
    
    cin >> p >> q >> c;
    dfs(p);
  }

  for (int i = 1; i <= n; i++)
    cout << cor[i] << " ";
  
  cout << endl;
}
