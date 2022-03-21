#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
const int maxn = 1e5+7;
int n, s; ll bit[maxn];

void upd(int k, ll x) {
  while (k <= s) {
    bit[k] = max(bit[k], x);
    k += k&-k;
  }
}

ll qry(int k) {
  ll q = 0;
  while (k >= 1) {
    q = max(q, bit[k]);
    k -= k&-k;
  }
  return q;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  map<pair<int, int>, ll> m;
  int a, b; ll w;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> w;
    m[{a, -b}] += w;
  }
  int i = 0;
  vector<pair<int, int>> c;
  vector<tuple<int, int, ll>> guests;
  for (auto it : m) {
    auto[a, b] = it.f; w = it.s;
    guests.pb({a, -b, w});
    c.pb({-b, i++});
  }
  sort(c.begin(), c.end());
  s = 1;
  for (int i = 0; i < guests.size(); i++) {
    if (i > 0 && c[i].f != c[i-1].f) s++;
    get<1>(guests[c[i].s]) = s;
  }
  ll ans = 0, k;
  for (auto[a, b, w] : guests) {
    k = qry(b-1) + w;
    ans = max(ans, k);
    upd(b, k);
  }
  cout << ans << '\n';
}
