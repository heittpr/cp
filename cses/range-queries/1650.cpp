#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+10;
int pref[maxn];
int n, q;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q; int k;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    pref[i] = pref[i-1] ^ k;
  }
  
  int a, b;
  while (q--) {
    cin >> a >> b;
    cout << (pref[a-1]^pref[b]) << '\n';
  }
}
