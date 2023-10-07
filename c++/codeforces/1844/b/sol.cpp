#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    if (n == 2) {
        cout << "2 1\n";
        return;
    }

    for (int i = 0, j = n; i < n; ++i) {
        if (i == 0) {
            cout << 2 << ' ';
        }
        else if (n / 2 == i) {
            cout << 1 << ' ';
        }
        else if (i == n - 1) {
            cout << 3 << '\n';
        }
        else {
            cout << j-- << ' ';
        }
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