#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int d, a, n; cin >> d >> a >> n;
    cout << (31-n+1) * (d + min(14,n-1)*a) << '\n';
}