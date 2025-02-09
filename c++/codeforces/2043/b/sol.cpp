#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, d;
    cin >> n >> d;
    cout << "1 ";
    if (d % 3 == 0 or n >= 3) {
        cout << "3 ";
    }
    if (d == 5) {
        cout << "5 ";
    }
    if (d == 7 or n >= 3) {
        cout << "7 ";
    }
    if (d == 9 or n >= 6 or (d % 3 == 0 and n >= 3)) {
        cout << "9";
    }
    cout << '\n';
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