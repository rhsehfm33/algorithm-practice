#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    if (n == 3) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (n % 2 == 0) {
            if (i % 2 == 0) {
                cout << "1 ";
            }
            else {
                cout << "-1 ";
            }
        }
        else {
            if (i % 2 == 0) {
                cout << n / 2 - 1 << ' ';
            }
            else {
                cout << -(n / 2) << ' ';
            }
        }
    }
    cout << '\n';
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