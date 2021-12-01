#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2*1e5+10;
int n, q, a, b, k;
ll pref[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    pref[i] = pref[i-1] + k;
  }
  while (q--) {
    cin >> a >> b;
    cout << pref[b]-pref[a-1] << '\n';
  }
}
