#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
  ll x, y;
  Point() : x(0), y(0) {}
  Point(ll x, ll y) : x(x), y(y) {}
  Point operator - (Point p) const { return Point(x-p.x, y-p.y); }
  ll operator * (Point p) const { return x*p.y - y*p.x; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Point a, b, c;
  int t; cin >> t;
  while (t--) {
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    ll cross = (c-a)*(b-a);
    if (cross < 0) cout << "LEFT\n";
    else if (cross > 0) cout << "RIGHT\n";
    else cout << "TOUCH\n";
  }
}
