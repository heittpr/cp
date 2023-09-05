#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define endl '\n'
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define int long long

const int maxn = 1e6 + 10;

int c[maxn], fim[maxn], ini[maxn], dp[maxn], add[maxn];

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, s; cin >> n >> s;
	vector<tuple<int,int,int>> events;
	for (int i = 1; i <= n; ++i) {
		int l, r; cin >> l >> r >> c[i];
		fim[i] = r, ini[i] = l;
		events.pb({l, 1, i});
		events.pb({r+1, 0, i});
	}
	sort(all(events));
	multiset<int> ativos;
	int desativo = 0, ans = 0; 
	for (auto [coord, tipo, id] : events) {
		if (tipo) {
			int melhor = 0;
			if (!ativos.empty()) {
				melhor = *prev(ativos.end()) - s * (1e9 - coord + 1);
			}
			melhor = max(melhor, desativo);	
			dp[id] = melhor + (fim[id] - coord + 1) * s - c[id]; 
			ans = max(ans, dp[id]);
			add[id] = melhor + s * (1e9 - coord + 1) - c[id];
			ativos.insert(add[id]);
		} else {
			desativo = max(desativo, dp[id]);
			ativos.erase(ativos.find(add[id]));
		}
	}
	cout << ans << endl;
}
