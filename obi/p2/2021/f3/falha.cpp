#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  map<string, int> freq;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    v[i] = s;
    freq[s]++;
  }
  int ans = 0;
  for (auto s : v) {
    set<string> m;
    for (int i = 0; i <= s.size(); i++)
      for (int j = 0; j+i <= s.size(); j++) {
        string z = s.substr(i, j);
        if (m.find(z) == m.end()) {
          ans += freq[z];
          m.insert(z);
        }
      }
  }
  cout << ans-n << '\n';
}
