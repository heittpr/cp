// Trabalho do Papa
// https://neps.academy/lesson/177

#include <bits/stdc++.h> 

#define MAXN 1001
#define MAXR 1000001

using namespace std;
typedef pair<int, int> par;
typedef map<par, int> memo;

struct caixa { int p, r; };
bool cmp (caixa a, caixa b) { return a.r - b.p > b.r - a.p; }

int N;
caixa cx[MAXN];
memo dp;

int knapsack(int i, int c) {
  if (i == N || c <= 0) return 0;

  par k = make_pair(i, c);

  memo::iterator it = dp.find(k);
  if (it != dp.end()) return it->second;

  int n = knapsack(i+1, c);
  int s = 0;

  if (cx[i].p <= c && cx[i].r >= 0)
    s = 1 + knapsack(i+1, min(c-cx[i].p, cx[i].r));

  return dp[k] = max(s,n);
}

int main() {
  cin >> N; 

  for (int i = 0; i < N; ++i) {
    cin >> cx[i].p >> cx[i].r;
    cx[i].r -= cx[i].p;
  }
 
  sort(cx, cx+N, cmp);
  cout << knapsack(0, MAXR) << endl;
}
