#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    if (n & 1) {
        for (int i = 0; i < n; ++i) {
            cout << 1 << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = 0; i < n; ++i) {
            cout << (i == 0 ? 1 : n + 1) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}