#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
  ll x, y;
  Point() : x(0), y(0) {}
  Point(ll x, ll y) : x(x), y(y) {}
  Point operator + (Point p) const { return Point(x+p.x, y+p.y); }
  Point operator - (Point p) const { return Point(x-p.x, y-p.y); }
  ll    operator * (Point p) const { return x*p.y - y*p.x; }
  bool  operator < (Point p) const { return x != p.x ? x < p.x : y < p.y; }
};

bool cw(Point a, Point b, Point c) { return (b-a)*(c-a) <= 0; }
bool ccw(Point a, Point b, Point c) { return (b-a)*(c-a) >= 0; }

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<Point> points(n);
  for (auto&[x,y] : points)
    cin >> x >> y;
  
  sort(points.begin(), points.end());
  vector<Point> up, lw; int i; 
  for (auto p : points) {
    while ((i=up.size()) >= 2 && !cw(up[i-2], up[i-1], p))
      up.pop_back();
    up.push_back(p);
    while ((i=lw.size()) >= 2 && !ccw(lw[i-2], lw[i-1], p))
      lw.pop_back();
    lw.push_back(p);
  }
  vector<Point> hull = up;
  for (i = lw.size()-2; i > 0; i--)
    hull.push_back(lw[i]);
  
  cout << hull.size() << '\n';
  for (auto[x,y] : hull)
    cout << x << ' ' << y << '\n';
}
