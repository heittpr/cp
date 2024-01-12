#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
#define gcd(x, y) __gcd(x, y)
using namespace std;
using ll = long long;
using ii = pair<int, int>;

struct pt {
  int x, y;
  pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
  pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
  int operator ^ (const pt p) const { return x*p.y - y*p.x; }
  friend istream& operator >> (istream& in, pt& p) { return in >> p.x >> p.y; }
};

ll sarea2(pt p, pt q, pt r) {
  return (q-p)^(r-q);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pt> pts(n);
  for (auto& p : pts) cin >> p;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    map<ii, int> cnt;
    for (int j = i+1; j < n; j++) {
      int a = pts[i].y - pts[j].y, b = pts[i].x - pts[j].x, g = gcd(a, b);
      cnt[{a/g, b/g}]++, ans = max(ans, cnt[{a/g, b/g}]);
    }
  }
  cout << ans+1 << '\n';
}
