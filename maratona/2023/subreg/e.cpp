#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define int long long

const int maxf = 1e6 + 10;

int freq[maxf], a[maxf], onde[maxf], dp[maxf];

ll f(int x) {

	int ans = 0;

	for (int i = 1e6 + 8; i >= x; --i) {
		dp[i] += freq[i], dp[onde[i]] += dp[i], ans += dp[i];
	}

	for (int i = 0; i <= 1e6 + 8; ++i) dp[i] = 0;

	return ans;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i], freq[a[i]]++;
	}
	for (int i = 1; i <= 1e6; ++i) {
		int tot = 0, cur = i;
		while (cur) {
			tot += cur % 10, cur /= 10;
		}
		onde[i] = i - tot;
	}
	
	int l = 0, r = 1e6, ans = 0;

	while (l <= r) {
		int md = l + (r-l+1)/2;
		if (f(md) >= k) {
			ans = md, l = md + 1;
		}
		else r = md - 1;
	}

	int resp = 0;
	
	while (ans) resp += ans % 10, ans /= 10;
	
	cout << resp << endl;
}
