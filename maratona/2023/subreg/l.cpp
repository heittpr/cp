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
	string s; cin >> s;
	int k; cin >> k;
	int n = s.size();
	vector<string> v(k);
	for (int i = 0; i < n; i++) v[i%k] += s[i];
	for (string &x : v)
		sort(all(x));
	int i = 0;
	string ans;
	vector<int> idx(k, 0);
	while (n--) {
		if (idx[i] < v[i].size()) ans += v[i][idx[i]++];
		i = (i+1)%k;
	}
	cout << ans << '\n';
}
