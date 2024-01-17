#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int maxn = 10010;
bool sieve[maxn];
vector<int> primes;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(sieve, 1, sizeof(sieve));
  sieve[0] = sieve[1] = 0;
  for (ll i = 2; i < maxn; i++)
    if (sieve[i] && i*i < maxn)
      for (ll j = i*i; j < maxn; j += i)
        sieve[j] = 0;
  for (int i = 2; i < maxn; i++)
    if (sieve[i]) primes.pb(i);
  map<int, int> cnt;
  for (int i = 0; i < 10; i++) {
    ll n; cin >> n;
    for (int p : primes)
      while (n%p == 0)
        n /= p, cnt[p]++;
  }
  ll ans = 1;
  for (auto[p, e] : cnt)
    ans *= (e+1);
  cout << ans%10 << '\n';
}
