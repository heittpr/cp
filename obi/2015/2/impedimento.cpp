// Impedimento! 

#include <iostream>
using namespace std;
#define endl "\n"

int l, r, d;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> l >> r >> d;
  cout << ((r > 50) && (l < r) && (r > d) ? 'S' : 'N') << endl;
}
