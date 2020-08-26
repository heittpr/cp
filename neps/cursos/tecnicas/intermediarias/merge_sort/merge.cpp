// Eu aprendi o MergeSort
// https://neps.academy/lesson/174

#include <iostream>
#include <vector>
using namespace std;

#define MIN -1000000001
typedef vector<int> vect;

void merge_sort(vect &v) {
  int s = v.size();
  if (s == 1) return;
  
  vect a,b;

  for (int i=0; i < s/2; ++i) a.push_back(v[i]);
  for (int i=s/2; i < s; ++i) b.push_back(v[i]);

  merge_sort(a);
  merge_sort(b);

  a.push_back(MIN);
  b.push_back(MIN);

  int ai=0, bi=0;

  for (int i=0; i<s; ++i) {
    if (a[ai] > b[bi]) {
      v[i] = a[ai];
      ai++;
    } else {
      v[i] = b[bi];
      bi++;
    }
  }

  return;
}

vect v;
int a, N;

int main() {
  cin >> N;

  for (int i=0; i < N; ++i) {
    cin >> a;
    v.push_back(a);
  }

  merge_sort(v);

  for (int i=0; i < N; ++i)
    cout << v[i] << " ";

  cout << endl;
}
