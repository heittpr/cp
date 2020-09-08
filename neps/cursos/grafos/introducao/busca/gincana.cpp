// Gincana
// https://neps.academy/lesson/203

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define endl "\n"
#define pb push_back
#define MAXN 1001
typedef vector<int> vi;

int n, m;
vi amigos[MAXN];
bool seen[MAXN];

void dfs(int x) {
  seen[x] = true;

  for (int amigo : amigos[x])
    if (!seen[amigo])
      dfs(amigo);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(seen, false, sizeof seen);

  cin >> n >> m;

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;

    amigos[a].pb(b);
    amigos[b].pb(a);
  }
   
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!seen[i]) {
      res++;
      dfs(i);
    }
  }

  cout << res << endl;
}
