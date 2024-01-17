#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int maxx = 32010;
int bit[maxx];

void add(int k, int x) {
  for (; k < maxx; k += k&-k)
    bit[k] += x;
}

int query(int k) {
  int s = 0;
  for (; k; k -= k&-k)
    s += bit[k];
  return s;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<ii> s(n);
  for (auto&[x, y] : s) cin >> x >> y, x++, y++;
  vector<int> ans(n);
  for (auto[x, y] : s)
    ans[query(x)]++, add(x, 1);
  for (int i : ans) cout << i << '\n';
}
