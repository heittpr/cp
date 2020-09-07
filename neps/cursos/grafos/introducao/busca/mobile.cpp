// Móbile
// https://neps.academy/lesson/208

#include <iostream>
#include <vector>

using namespace std;
#define endl "\n"
#define MAXN 100001
#define pb push_back
typedef vector<int> vi;

int n, v[MAXN];
vi mobile[MAXN];

int dfs(int i) {
  int t = 1;

  for (int j = 0; j < mobile[i].size(); j++)
    t += dfs(mobile[i][j]);

  return v[i] = t;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    mobile[b].pb(a);
  }

  dfs(0);

  for (int i = 0; i <= n; i++) {
    for (int j = 1; j < mobile[i].size(); j++) {
      if (v[mobile[i][j]] != v[mobile[i][j-1]]) {
        cout << "mal" << endl;
        return 0;
      }
    }
  }

  cout << "bem" << endl;
}
