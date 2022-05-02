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

  T operator % (Point p) const {
    return x*p.x + y*p.y;
  }

  double dist(Point p) const {
    T dx = x-p.x, dy = y-p.y;
    return sqrt(dx*dx + dy*dy);
  }

  double distLine(Point a, Point b) const {
    return abs((*this-a)*(b-a))/a.dist(b);
  }
  
  double distSegment(Point a, Point b) const {
    if ((*this-a)%(b-a) < 0) return this->dist(a);
    if ((*this-b)%(a-b) < 0) return this->dist(b);
    return this->distLine(a, b);
  }
};
typedef Point<long long> point;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  point a, b, p;
  cin >> a.x >> a.y >> b.x >> b.y >> p.x >> p.y;
  cout << p.distSegment(a, b) << '\n';
}
