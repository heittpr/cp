#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int n, bit[maxn];

int sum(int k) {
  int s = 0;
  while (k >= 1) {
    s += bit[k];
    k -= k&-k;
  }
  return s;
}

void add(int k) {
  while (k <= n) {
    bit[k]++;
    k += k&-k;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  while (cin >> n) {
    memset(bit, 0, sizeof(bit));
    long long ans = 0;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    for (int i = n-1; i >= 0; i--) {
      add(v[i]);
      ans += sum(n)-sum(v[i]);
    }
    cout << ans << '\n';
  }
}
