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
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	vector<ll> pref(n+1);
	ll par = 1, impar = 0;
	for (int i = 1; i <= n; i++) {
		pref[i] = v[i] + pref[i-1];
		if (pref[i] % 2) impar++;
		else par++;
	}
	cout << par*impar << '\n';
}
