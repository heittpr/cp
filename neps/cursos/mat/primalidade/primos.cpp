#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n; cin >> n;
  for (ll i = 2; i <= n; i++) {
    for (ll j = 2; j*j <= i; j++)
      if (i%j == 0) goto nxt;
    cout << i << ' ';
    nxt:;
  }
  cout << '\n';
}
