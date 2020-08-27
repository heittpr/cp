// Linhas Cruzadas
// https://neps.academy/lesson/180

#include <iostream>
#include <vector>

using namespace std;

#define INF 60001
typedef vector<int> vint;

int N;
vint l;

int inversoes(vint &v) {
  int s = v.size();
  if (s == 1) return 0;

  vint a, b;
  int inv=0;

  for (int i=0; i < s/2; ++i) a.push_back(v[i]);
  for (int i=s/2; i < s; ++i) b.push_back(v[i]);

  inv += inversoes(a);
  inv += inversoes(b);

  a.push_back(INF);
  b.push_back(INF);

  int ai=0, bi=0;

  for (int i = 0; i<s; i++)
    if (a[ai] <= b[bi]) {
      v[i] = a[ai];
      ai++;
    } else {
      v[i] = b[bi];
      bi++;
      
      inv += a.size()-ai-1;
    }

  return inv;
}

int main() {
  cin >> N;

  int j;
  for (int i = 0; i < N; i++) {
    cin >> j;
    l.push_back(j);
  }

  cout << inversoes(l) << endl;
}
