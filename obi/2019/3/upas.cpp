// Coleção de Upas

#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define endl "\n"
#define pb push_back
#define maxn 100010

int n, m;
set<int> res;
vector<int> adj[maxn];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  
  int u, v;
  while (m--) {
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  for (int i = n; i >= 1; i--) {
    bool ok = true;
    
    for (int j : adj[i])
      if (res.count(j)) {
        ok = false;
        break;
      }

    if (ok) res.insert(i);
  }

  cout << (int) res.size() << endl;
  
  for (int i : res)
    cout << i << " ";

  cout << endl;
}
