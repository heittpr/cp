#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b; cin >> a >> b;
  vector<int> da, db;
  while (a) {
    da.pb(a%10);
    a /= 10;
  }
  while (b) {
    db.pb(b%10);
    b /= 10;
  }
  int n = max(da.size(), db.size());
  da.resize(n); db.resize(n);
  vector<int> x, y;
  for (int i = 0; i < n; i++) {
    if (da[i] >= db[i]) x.pb(da[i]);
    if (db[i] >= da[i]) y.pb(db[i]);
  }
  int ansx=-1, ansy=-1, ix = 1, iy = 1;
  if (!x.empty()) {
    ansx = 0;
    for (int i : x) {
      ansx += ix*i;
      ix *= 10;
    }
  }
  if (!y.empty()) {
    ansy = 0;
    for (int i : y) {
      ansy += iy*i;
      iy *= 10;
    }
  }
  if (ansx > ansy) swap(ansx, ansy);
  cout << ansx << ' ' << ansy << '\n';
}
