// Letras

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
#define pb push_back
#define endl "\n"

int lis(string &s) {
  vi p;

  for (int i = 0; i < s.size(); i++) {
    vi::iterator it = upper_bound(p.begin(), p.end(), s[i]);

    if (it == p.end()) p.pb(s[i]);
    else *it = s[i];
  }
  
  return p.size();
}

string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> s;
  cout << lis(s) << endl;
}
