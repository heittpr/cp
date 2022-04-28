#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> struct Point {
  T x, y;
  Point() {}
  Point(T x, T y) : x(x), y(y) {}
};

ll area(vector<Point<ll>> poly) {
  ll ans = 0;
  for (int i = 0; i < poly.size()-1; i++)
    ans += (poly[i+1].y + poly[i].y)*(poly[i+1].x - poly[i].x);
  return abs(ans/2);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<Point<ll>> poly(n);
  for (auto&[x, y] : poly)
    cin >> x >> y;
  poly.push_back(poly[0]);
  cout << area(poly) << '\n';
}
