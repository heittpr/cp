#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
ll l[maxn], r[maxn], c[maxn];
int t, n, a, b, x;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> l[1] >> r[1] >> c[1];
    a = b = x = 1;
    cout << c[1] << '\n';
    for (int i = 2; i <= n; i++) {
      cin >> l[i] >> r[i] >> c[i];
      if (l[i] < l[a] || (l[i] == l[a] && c[i] < c[a])) a = i;
      if (r[i] > r[b] || (r[i] == r[b] && c[i] < c[b])) b = i;
      if (r[i]-l[i] > r[x]-l[x] || (r[i]-l[i] == r[x]-l[x] && c[i] < c[x])) x = i;
      if (l[a] < l[x] || r[b] > r[x]) cout << c[a] + c[b] << '\n';
      else cout << min(c[x], c[a]+c[b]) << '\n';
    }
  }
}
