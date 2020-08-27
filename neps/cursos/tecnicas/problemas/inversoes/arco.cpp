// Arco e Flecha
// https://neps.academy/lesson/181

#include <iostream>
#include <vector>

using namespace std;

#define INF 2000000000001
typedef long long ll;
typedef vector<ll> vll;

int N;
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

  a.push_back(INF);
  b.push_back(INF);

  int ai=0, bi=0;

  for (int i=0; i<s; i++) {
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
  cin >> N;

  ll x,y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    v.push_back(x*x + y*y);
  }

  cout << inversoes(v) << endl;
}
