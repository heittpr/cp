// Ponto do meio

#include <iostream>
using namespace std;
typedef long long ll;
#define endl "\n"

int n;
ll s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  cin >> n;
  s = 1 + (1<<n);

  cout << s*s << endl;
}
