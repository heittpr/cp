#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define pb push_back
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int n, m;
vector<int> a, b;

bool check(int k) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < m && abs(a[i]-b[j]) > k) j++;
    if (j >= m) return false;
    j++;
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  a.resize(n), b.resize(m);
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;
  if (n > m) swap(n, m), swap(a, b);
  sort(all(a)), sort(all(b));
  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int md = l+(r-l)/2;
    if (check(md)) ans = md, r = md-1;
    else l = md+1;
  }
  cout << ans << '\n';
}
