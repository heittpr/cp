#include <bits/stdc++.h>
using namespace std;

template <class T> struct Point {
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x, T y) : x(x), y(y) {}

  Point operator - (Point p) const {
    return Point(x-p.x, y-p.y);
  }

  T operator * (Point p) const {
    return x*p.y - y*p.x;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Point<long long> a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  cout << ((b-a)*(c-a) > 0 ? 1 : -1) << '\n';
}
