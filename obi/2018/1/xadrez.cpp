// Xadrez

#include <iostream>
using namespace std;
#define endl "\n"

int l, c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> l >> c;
  cout << (l + c + 1) % 2 << endl;
}
