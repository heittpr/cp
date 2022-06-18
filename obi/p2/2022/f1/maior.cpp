#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s; cin >> n >> m >> s;
    for (int i = m; i >= n; i--) {
        int t = 0;
        for (int x = i; x; x /= 10)
            t += x%10;
        if (t == s) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}