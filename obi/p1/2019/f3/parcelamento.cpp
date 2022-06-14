// Parcelamento sem juros

#include <iostream>
using namespace std;
#define endl "\n"

int v, p, r, q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> v >> p;
  
  q = v / p;
  r = v % p;

  for (int i = 1; i <= p; i++)
    cout << q + (i <= r) << endl;
}
