// Matriz super-legal

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
#define endl "\n";
#define MAXLC 1001

int a[MAXLC][MAXLC];
int h[MAXLC];
int l, c;

int rect() {
  stack<int> s;
  int i = 0, t;
  int res = 0;

  while (i < c-1) {
    if (s.empty() || h[s.top()] <= h[i]) s.push(i++);
    else {
      t = s.top(); s.pop();
      res = max(res, (h[t]+1) * (s.empty() ? i + 1: i - s.top()));
    }
  }

  while(!s.empty()) {
    t = s.top(); s.pop();
    res = max(res, (h[t]+1) * (s.empty() ? i + 1: i - s.top()));
  }

  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> l >> c;
  for (int i = 0; i < l; i++)
    for (int j = 0; j < c; j++)
      cin >> a[i][j];

  int res = min(l, c);

  for (int i = 0; i < l-1; i++) {
    for (int j = 0; j < c-1; j++) 
      h[j] = a[i][j] + a[i+1][j+1] <= a[i+1][j] + a[i][j+1] ? h[j] + 1 : 0;
    res = max(res, rect());
  }

  cout << res << endl;
}
