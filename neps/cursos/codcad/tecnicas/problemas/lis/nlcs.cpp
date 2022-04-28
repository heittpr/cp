// Não é só mais um LCS!
// https://neps.academy/lesson/187

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
typedef vector<int> vi;

int n, m;
vi seq;
unordered_map<int, int> s;

int lis(vi &v) {
  vi p = { v[0] };

  for (int i = 1; i < v.size(); i++) {
    vi::iterator it = lower_bound(p.begin(), p.end(), v[i]);
    
    if (it == p.end()) p.pb(v[i]);
    else *it = v[i];
  }

  return p.size();
}

int main() { 
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int j;
  
  for (int i = 0; i < n; i++) {
    cin >> j;
    s[j] = i;
  }
  
  for (int i = 0; i < m; i++) {
    cin >> j;

    if (s.find(j) != s.end())
      seq.pb(s[j]);
  }

  cout << lis(seq) << endl;
}
