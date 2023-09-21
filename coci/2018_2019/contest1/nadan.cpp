#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> k >> n;
  vector<int> v(n);
  int cur = 1;
  for (int i = 0; i < n; i++) {
    v[i] = cur++;
    k -= v[i];
  }
  v[n-1] += k;
  for (int i : v) cout << i << '\n';
}
