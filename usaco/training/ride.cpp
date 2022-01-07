/*
ID: heitorl1
LANG: C++14
TASK: ride
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 47;

int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  string a, b;
  cin >> a >> b;
  int sa=1, sb=1;
  for (char c : a) sa = (sa*(c-'A'+1))%mod;
  for (char c : b) sb = (sb*(c-'A'+1))%mod;
  cout << (sa == sb ? "GO\n" : "STAY\n");
}
