#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int m, n, in[maxn], out[maxn];
long long ans, sum;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> m >> n;
  int x, v, y;
  while (m--) {
    cin >> x >> v >> y;
    out[x] += v, in[y] += v, sum += v;
  }
  for (int i = 1; i <= n; i++)
    ans += abs(in[i]-out[i]);
  ans /= 2;
  cout << (ans != sum ? 'S' : 'N') << '\n';
  cout << ans << '\n';
}
