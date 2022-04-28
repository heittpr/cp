// Escalonamento Ótimo
// https://neps.academy/lesson/213

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> vi;
#define endl "\n"
#define pb push_back
#define MAXN 50001

int n, m;
vi grafo[MAXN];
int grau[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  memset(grau, 0, sizeof grau);

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;

    grau[b]++;
    grafo[a].pb(b);
  }

  priority_queue<int> zero;
  for (int i = 0; i < n; i++)
    if (grau[i] == 0) zero.push(-i);

  vi res;
  while (!zero.empty()) {
    int v = -zero.top(); zero.pop();
    res.pb(v);

    for (int u : grafo[v]) {
      grau[u]--;

      if (grau[u] == 0)
        zero.push(-u);
    }
  }

  if (res.size() < n)
    cout << "*" << endl;
  else for (int i : res)
    cout << i << endl;
}
