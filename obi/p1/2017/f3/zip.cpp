// Zip

#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n"

int l, c;
int l1, l2, c1, c2;
int m[3] = {2, 3, 1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> l1 >> l2 >> c1 >> c2;

  l = m[min(abs(l1 - l2), 2)] * (l1 + l2);
  c = m[min(abs(c1 - c2), 2)] * (c1 + c2);

  if (l > c)
    cout << "Lia" << endl;
  else if (c > l)
    cout << "Carolina" << endl;
  else
    cout << "empate" << endl;
}
