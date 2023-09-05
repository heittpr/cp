#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, h; cin >> n >> h;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x <= h) ++ans;
	}
	cout << ans << endl;
}
