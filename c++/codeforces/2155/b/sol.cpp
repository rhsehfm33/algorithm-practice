#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    k = n * n - k;
    if (k == 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (k > 0) {
                if (x + y == 0) {
                    cout << "R";
                } else if (x == 0) {
                    cout << "L";
                } else {
                    cout << "U";
                }
            } else {
                cout << "D";
            }
            --k;
        }
        cout << '\n';
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