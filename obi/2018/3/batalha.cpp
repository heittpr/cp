// Batalha

#include <iostream>
using namespace std;
#define endl "\n"

int a1, d1, a2, d2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> a1 >> d1 >> a2 >> d2;

  if      (d1 != a2 && d2 != a1) cout << -1 << endl;
  else if (d2 != a1)             cout <<  1 << endl;
  else if (d1 != a2)             cout <<  2 << endl;
  else                           cout << -1 << endl;
}
