#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    array<bool, 3> d1{};
    d1[n & 1 ^ 1] = true;
    for (int i = 0; i < n; ++i) {
        array<bool, 3> d2{};
        char xi;
        cin >> xi;
        if (xi == 'a') {
            d2[1] = d1[0];
            d2[2] = d1[1];
        } else if (xi == 'b') {
            d2[0] = d1[1];
            d2[1] = d1[2];
        } else {
            d2[0] = d1[1];
            d2[1] = d1[0] | d1[2];
            d2[2] = d1[1];
        }
        d1 = d2;
    }
    if (d1[0] | d1[1] | d1[2]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}