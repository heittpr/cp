// Tá ligado?
// https://neps.academy/lesson/205

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 100001
#define endl "\n"
typedef vector<int> vi;

int n, m;
vi v[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  int t, a, b;

  while(m--) {
    cin >> t >> a >> b;
    
    if (t) {
      v[a].push_back(b);
      v[b].push_back(a);
    } else {
      cout << int(find(v[a].begin(), v[a].end(), b) != v[a].end()) << endl;
    }
  }
}
