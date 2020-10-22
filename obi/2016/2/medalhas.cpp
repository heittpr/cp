// Medalhas

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
#define endl "\n"

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  pair<int, int> t[3];

  for (int i = 0; i < 3; i++) {
    cin >> t[i].first;
    t[i].second = i+1;
  }

  sort(t, t+3);

  for (int i = 0; i < 3; i++)
    cout << t[i].second << endl;
}
