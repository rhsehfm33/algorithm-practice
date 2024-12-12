#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    if (n == 1 or n == 3) {
        cout << "-1\n";
        return;
    }
    if (n % 2) {
        cout << string(n - 4, '3') + "6366\n";
    } else {
        cout << string(n - 2, '3') + "66\n";
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