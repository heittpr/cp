#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define endl '\n'
#define int long long
using namespace std;
using ll = long long;
using ii = pair<int, int>;

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }
	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int (ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator += (const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -= (const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *= (const m&a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /= (const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -() { return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e%(p-1));
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

const int MOD = 998244353;
typedef mod_int<MOD> mint;

void ntt(vector<mint>& a, bool rev) {
	int n = a.size(); auto b = a;
	assert(!(n&(n-1)));
	mint g = 1;
	while ((g^((MOD - 1) / 2)) == mint(1)) g += 1;
	if (rev) g = 1/g;
	for (int step = n/2; step; step /= 2) {
		mint w = g^((MOD-1) / (n/step)), wn = 1;
		for (int i = 0; i < n/2; i += step) {
			for (int j = 0; j < step; j++) {
				auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
				b[i+j] = u + v; b[i + n/2 + j] = u - v;
			}
			wn = wn * w;
		}
		swap(a, b);
	}
	if (rev) {
		auto n1 = mint(1) / n;
		for (auto& x : a) x *= n1;
	}
}

vector<mint> convolution(vector<mint>& a, vector<mint>& b) {
	vector<mint> l(a.begin(), a.end()), r(b.begin(), b.end());
	int N = l.size()+r.size()-1, n = 1;
	while (n <= N) n *= 2;
	l.resize(n);
	r.resize(n);
	ntt(l, false);
	ntt(r, false);
	for (int i = 0; i < n; i++) l[i] *= r[i];
	ntt(l, true);
	l.resize(N);
	return l;
}

const int maxn = 2e5 + 100;

mint fat[maxn];

int n;

vector<mint> newf(vector<mint> f, mint k) {
	vector<mint> a(n+1), b(n+1);
	vector<mint> pots(n+1, 1);
	for (int i = 1; i <= n; ++i) pots[i] = pots[i-1] * k;
	for (int i = 0; i <= n; ++i) {
		a[i] = fat[i] * f[i];
		b[i] = pots[n - i] / fat[n - i];
	}
	// for (int i = 0; i <= n; ++i) cout << a[i] << ' '; cout << endl;
	// for (int i = 0; i <= n; ++i) cout << b[i] << ' '; cout << endl;
	auto res = convolution(a, b);
	vector<mint> resp;
	for (int i = 0; i <= n; ++i) {
		resp.pb(res[i + n] / fat[i]);
	}	
	return resp;
}

const int mod = 998244353;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int k; cin >> n >> k;
	fat[0] = 1;
	for (int i = 1; i <= 2 * n; ++i) fat[i] = fat[i-1] * (mint)i;
	vector<mint> p(n+1), q(n+1);
	for (auto& x : p) cin >> x;
	for (auto& x : q) cin >> x;
	// computar coeffs de P(x + k), Q(x - k) e somar ambos
	newf(p, k), newf(q, -k);
	auto p2 = newf(p, k), q2 = newf(q, -k);
	for (int i = 0; i <= n; ++i) {
		// considerar overflow do mod aqui??
		cout << p2[i] + q2[i] << ' ';
	}
}
