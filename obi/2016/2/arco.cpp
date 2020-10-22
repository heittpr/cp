// Arco e Flecha

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define pb push_back
#define INF 2000000000001

int n;
vll v;

ll inversoes(vll &v) {
  int s = v.size();
  if (s == 1) return 0;

  vll a,b;
  ll inv=0;

  for (int i=0; i < s/2; i++) a.push_back(v[i]);
  for (int i=s/2; i < s; i++) b.push_back(v[i]);

  inv += inversoes(a);
  inv += inversoes(b);

  a.pb(INF);
  b.pb(INF);

  int ai=0, bi=0;

  for (int i=0; i < s; i++) {
    if (a[ai] <= b[bi]) {
      v[i] = a[ai];
      ai++;

      inv += b.size()-bi-1;
    } else {
      v[i] = b[bi];
      bi++;
    }
  }

  return inv;
}

int main() {
  cin >> n;

  ll x,y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.pb(x*x + y*y);
  }

  cout << inversoes(v) << endl;
}
