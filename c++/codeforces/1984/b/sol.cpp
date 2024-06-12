#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll x;
    cin >> x;
    while (x >= 10) {
        if (x % 10 == 9) {
            cout << "NO\n";
            return;
        }
        x = x / 10 - 1;
    }

    if (x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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