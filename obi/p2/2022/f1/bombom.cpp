#include <bits/stdc++.h>
using namespace std;

map<char, int> v = {{'A', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    char f, d, n; cin >> f >> d;
    int a = 0;
    for (int i = 0; i < 3; i++) {
        cin >> f >> n;
        a += v[f];
        if (n == d) a += 4;
    }
    int b = 0;
    for (int i = 0; i < 3; i++) {
        cin >> f >> n;
        b += v[f];
        if (n == d) b += 4;
    }
    if (a > b) cout << "Luana\n";
    else if (a == b) cout << "empate\n";
    else cout << "Edu\n";
}