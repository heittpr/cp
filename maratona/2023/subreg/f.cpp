#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define int long long

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int d, c, r; cin >> d >> c >> r;
	int ans = 0;
	vector<int> v1(c), v2(r);
	for (auto&x : v1) cin >> x;
	for (auto&x : v2) cin >> x;
	int i = 0, j = 0;
	while (true) {
		if (i < c && d >= v1[i]) {
			++ans, d -= v1[i++];
		} else {
			if (j == r) break;
			d += v2[j++], ++ans;
		}
	}
	cout << ans << endl;
}
