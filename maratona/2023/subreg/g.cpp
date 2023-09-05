#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define sq(x) ((x)*(ll)(x))

struct pt {
	int x, y;
	pt (int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ll sarea2(pt p, pt q, pt r) {
	return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) {
	return sarea2(p, q, r) >= 0;
}

vector<pt> convex_hull(vector<pt> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (v.size() <= 1) return v;
	vector<pt> l, u;
	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i]))
			l.pop_back();
		l.push_back(v[i]);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i]))
			u.pop_back();
		u.push_back(v[i]);
	}
	l.pop_back(); u.pop_back();
	for (pt i : u) l.push_back(i);
	return l;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pt> pts(n);
	map<ii, int> id;
	for (int i = 1; i <= n; i++) {
		cin >> pts[i-1];
		id[{pts[i-1].x, pts[i-1].y}] = i;
	}
	vector<pt> ch = convex_hull(pts);
	vector<int> ans;
	for (auto &p : ch) {
		ans.pb(id[{p.x, p.y}]);
	}
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}
