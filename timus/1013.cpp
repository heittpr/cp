#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
#define int unsigned long long
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using i128 = __int128;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
ll mod;

template<class T, int N> struct Matrix {
  typedef Matrix M;
  array<array<T, N>, N> d{};
  M operator*(const M& m) const {
    M a;
    rep(i,0,N) rep(j,0,N)
      rep(k,0,N) (a.d[i][j] += d[i][k]*m.d[k][j]) %= mod;
    return a;
  }
  vector<T> operator*(const vector<T>& vec) const {
    vector<T> ret(N);
    rep(i,0,N) rep(j,0,N) (ret[i] += d[i][j] * vec[j]) %= mod;
      return ret;
    }
    M operator^(ll p) const {
      assert(p >= 0);
      M a, b(*this);
      rep(i,0,N) a.d[i][i] = 1;
      while (p) {
        if (p&1) a = a*b;
        b = b*b;
        p >>= 1;
      }
      return a;
    }
};

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, k; cin >> n >> k >> mod;
  Matrix<i128, 3> x;
  x.d = {{{k-1, k-1}, {1, 0}}};
  i128 ans = ((x^(n-1))*(vector<i128>{k-1, 1}))[0];
  cout << ((ll)(ans%mod)) << '\n';
}
