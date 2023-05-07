#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+10;
const int logn = 18;
int st[maxn][logn];
int _log[maxn];
int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 2; i <= n+1; i++)
    _log[i] = _log[i/2] + 1;
  
  for (int i = 1; i <= n; i++)
    cin >> st[i][0];
  for (int j = 1; j <= logn; j++)
    for (int i = 1; i+(1<<j) <= n+1; i++)
      st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);
  
  int a, b;
  while (q--) {
    cin >> a >> b;
    int j = _log[b-a+1];
    cout << min(st[a][j], st[b-(1<<j)+1][j]) << '\n';
  }
}
