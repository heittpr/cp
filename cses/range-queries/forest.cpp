#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, pref[maxn][maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; char k; cin >> n >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> k;
      if (k == '*') pref[i][j]++;
      pref[i][j] += pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
    }
  int a, b, c, d;
  while (q--) {
    cin >> a >> b >> c >> d;
    cout << pref[c][d] - pref[a-1][d] - pref[c][b-1] + pref[a-1][b-1] << '\n';
  }
}
