// Pandemia

#include <iostream>
#include <vector>

using namespace std;
#define endl "\n"
int n, m, i, r;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  cin >> i >> r;

  vector<bool> mark(n+1);

  int a;
  for (int p = 1; p <= m; p++) {
    cin >> a;
    
    vector<int> presentes;
    presentes.resize(a);

    if (p == r) mark[i] = true;

    bool ok = true;
    for (int q = 0; q < a; q++) {
       cin >> presentes[q];

       if (mark[presentes[q]])
         ok = false;
    }

    if (!ok)
      for (int amigo : presentes)
        mark[amigo] = true;
  }

  int res = 0;
  for (bool k : mark)
    if (k) res ++;

  cout << res << endl;
}
