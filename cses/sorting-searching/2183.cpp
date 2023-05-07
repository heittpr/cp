#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  vector<int> x(n);
  for (int &i : x) cin >> i;
  sort(x.begin(), x.end());
 
  ll s = 0;
  for (int i : x) {
    if (s+1 < i) break;
    s += i;
  }

  cout << s+1 << '\n';
}
