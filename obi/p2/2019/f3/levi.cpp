#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
const int maxn = 5e5+5;
int n, p, q;
ll bit[maxn];

void add(int k, int x) {
  for (; k < maxn; k += k&-k)
    bit[k] += x;
}

int sum(int k) {
  int s = 0;
  for (; k >= 1; k -= k&-k)
    s += bit[k];
  return s;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> p >> q;
  vector<pair<ll, ll>> v(n);
  for (auto&[x, y] : v)
    cin >> x >> y;
  sort(v.begin(), v.end());
  if (q < 0) p *= -1, q *= -1;
  vector<ll> f, g;
  for (auto[x, y] : v)
    f.push_back(q*y - p*x);
  g = f;
  sort(g.begin(), g.end());
  g.resize(unique(g.begin(), g.end()) - g.begin());
  for (auto& i : f)
    i = lower_bound(g.begin(), g.end(), i) - g.begin() + 1;
  ll ans = 0;
  for (auto i : f) {
    ans += sum(i);
    add(i, 1);
  }
  cout << ans << '\n';
}
