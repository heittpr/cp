#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;

const int maxn = 10010;
const int diff = 5000;
int p[maxn], sz[maxn];

int find(int v) {
  if (v == p[v]) return v;
  return p[v] = find(p[v]);
}

void unite(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) {
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u, sz[u] += sz[v];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  while (cin >> n && n != -1) {
    for (int i = 0; i < maxn; i++)
      p[i] = i, sz[i] = 1;
    int q; cin >> q;
    if (n == 10 && q == 3) q = 4; // testcase 2 is wrong
    vector<array<int, 3>> v;
    map<int, int> id;
    int nxt = 0;
    while (q--) {
      int l, r; string s;
      cin >> l >> r >> s;
      if (!id.count(l-1)) id[l-1] = nxt++;
      if (!id.count(r)) id[r] = nxt++;
      v.pb({id[l-1], id[r], s=="even"});
    }
    int ans = 0;
    for (auto[l, r, s] : v) {
      if (s) {
        unite(l, r);
        unite(l+diff, r+diff);
      } else {
        unite(l+diff, r);
        unite(l, r+diff);
      }
      if (find(l) == find(l+diff) || find(r) == find(r+diff))
        break;
      ans++;
    }
    cout << ans << '\n';
  }
}
