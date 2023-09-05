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
	int n; cin >> n;
	vector<int> a(n), mark(n+1);
	int tot = 0;
	for (int &i : a) {
		cin >> i;
		if (!mark[i-1]) tot++;
		mark[i] = 1;
	}
	int ans = 0, p = 1;
	while (p < tot) {
		p *= 2, ans++;
	}
	cout << ans << '\n';
}
