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
typedef Point<long long> point;

bool clockwise(point a, point b, point c) {
  return (b-a)*(c-a) < 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  point p1, q1, p2, q2;
  cin >> p1.x >> p1.y >> q1.x >> q1.y;
  cin >> p2.x >> p2.y >> q2.x >> q2.y;
  if ((clockwise(p1, q1, q2) != clockwise(p1, q1, p2)) &&
      (clockwise(p2, q2, q1) != clockwise(p2, q2, p1))) cout << "1\n";
  else cout << "0\n";
}
