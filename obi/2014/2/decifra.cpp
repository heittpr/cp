// Decifra

#include <iostream>
#include <string>

using namespace std;
#define endl "\n"

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string perm, msg;
  cin >> perm >> msg;

  for (char c: msg)
    cout << perm[c - 'a'];
  
  cout << endl;
}
