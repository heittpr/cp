#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
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

bool col(pt p, pt q, pt r) {
  return sarea2(p, q, r) == 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<pt> pts(n);
  for (auto& p : pts) cin >> p;
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++) {
      int cur = 2;
      for (int k = j+1; k < n; k++)
        if (col(pts[i], pts[j], pts[k])) cur++;
      ans = max(ans, cur);
    }
  cout << ans << '\n';
}
