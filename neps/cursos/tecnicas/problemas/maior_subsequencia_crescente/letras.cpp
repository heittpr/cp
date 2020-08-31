// Letras
// https://neps.academy/lesson/184

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<int> vi;

int lis(string &s) {
  vi p;

  for (int i = 0; i < s.size(); i++) {
    vi::iterator it = upper_bound(p.begin(), p.end(), s[i]);
    
    if (it == p.end()) p.pb(s[i]);
    else *it = s[i];
  }

  return p.size();
}

string S;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> S;
  cout << lis(S) << "\n";
}
