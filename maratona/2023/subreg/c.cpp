#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int maxn = 2e5 + 100;

vector<int> g[maxn];

int v[maxn], res[maxn], ans[maxn];
vector<int> cur;

void dfs(int u, int p) {
	int tmp = -1;
	auto it = lower_bound(all(cur), v[u]);
	int i = it - cur.begin();
	if (it == cur.end()) cur.pb(v[u]);
	else tmp = cur[i], cur[i] = v[u];
	ans[u] = cur.size();
	for (auto v2 : g[u]) {
		if (v2 == p) continue;
		dfs(v2, u);
	}
	if (tmp == -1) cur.pop_back();
	else cur[i] = tmp;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	if (n == 1) return 0;
	for (int i = 2; i <= n; ++i) {
		int x; cin >> x;
		g[i].pb(x), g[x].pb(i);
	}
	for (int i = 1; i <= n; ++i) cin >> v[i];
	dfs(1, 1);
	for (int i = 2; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
}
