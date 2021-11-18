#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n; n--;
  vector<string> ans = {"0", "1"};

  while (n--) {
    vector<string> l = ans;
    for (int i = 0; i < l.size(); i++)
      ans[i] = "0" + l[i];
    for (int i = l.size()-1; i >= 0; i--)
      ans.pb("1" + l[i]);
  }

  for (auto s : ans) cout << s << '\n';
}
