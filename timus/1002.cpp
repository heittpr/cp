#include <bits/stdc++.h>
using namespace std;

const int inf = 50010;
map<char, string> m = {
  {'1', "ij"}, {'2', "abc"}, {'3', "def"}, {'4', "gh"}, {'5', "kl"},
  {'6', "mn"}, {'7', "prs"}, {'8', "tuv"}, {'9', "wxy"}, {'0', "oqz"}
};

bool match(int i, string& s, string& w) {
  for (int j = 0; j < w.size(); j++) {
    bool ok = false;
    for (char c : m[s[i+j]])
      if (w[j] == c) {
        ok = true;
        break;
      }
    if (!ok) return false;
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  while (cin >> s && s != "-1") {
    int n; cin >> n;
    vector<string> dict(n);
    for (auto &w : dict) cin >> w;
    int l = s.size();
    int dp[l+1];
    memset(dp, 0, sizeof(dp));
    string ans[l+1];
    for (int i = 0; i < l; i++)
      dp[i] = inf;
    for (int i = l-1; i >= 0; i--) {
      for (auto& w : dict)
        if (w.size() <= l-i && match(i, s, w)) {
          if (dp[i] > 1+dp[i+w.size()]) {
            dp[i] = 1+dp[i+w.size()];
            ans[i] = w;
          }
        }
    }
    if (dp[0] != inf) {
      for (int i = 0; i < l; i += ans[i].size())
        cout << ans[i] << ' ';
      cout << '\n';
    } else cout << "No solution.\n";
  }
}
