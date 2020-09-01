// Sequência da Onda
// https://neps.academy/lesson/185

#include <bits/stdc++.h>
using namespace std;

#define MAXM 100001
#define pb push_back
typedef vector<int> vi;

int m, crescente[MAXM], decrescente[MAXM];
vi onda;

void lis(vi &s) {
  vi p = { s[0] };

  for (int i = 1; i < m; i++) {
    vi::iterator it = lower_bound(p.begin(), p.end(), s[i]);
    
    if (it == p.end()) {
      p.pb(s[i]);
      crescente[i] = p.size();
    } else {
      *it = s[i];
      crescente[i] = (it - p.begin()) + 1;
    }
  }
}

void lds(vi &s) {
  vi p = { s[m-1] };

  for (int i = m-2; i >= 0; i--) {
    vi::iterator it = lower_bound(p.begin(), p.end(), s[i]);
    
    if (it == p.end()) {
      p.pb(s[i]);
      decrescente[i] = p.size();
    } else {
      *it = s[i];
      decrescente[i] = (it - p.begin()) + 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m;

  int j;
  for (int i = 0; i < m; i++) {
    cin >> j;
    onda.pb(j);
  }

  lis(onda);
  lds(onda);

  int resp = 0;
  
  for (int i = 0; i < m; i++) {
    int j = min(crescente[i], decrescente[i]);

    if (j > resp)
      resp = j;
  }
  
  cout << 2*resp - 1 << "\n";
}
