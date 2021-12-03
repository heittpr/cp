#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+10;
const int logn = 18;
int st[maxn][logn];
int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  
  for (int i = 1; i <= n; i++)
    cin >> st[i][0];
  for (int j = 1; j <= logn; j++)
    for (int i = 1; i+(1<<j) <= n+1; i++)
      st[i][j] = st[i][j-1] ^ st[i + (1<<(j-1))][j-1];
  
  int a, b;
  while (q--) {
    cin >> a >> b;
    int ans = 0;
    for (int j = logn; j >= 0; j--)
      if ((1<<j) <= b-a+1) {
        ans ^= st[a][j];
        a += 1<<j;
      }
    cout << ans << '\n';
  }
}
