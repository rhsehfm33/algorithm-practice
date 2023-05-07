#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    
    if (n % 2) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (i % 2) {
            cout << i + 1 << ' ';
        }
        else {
            cout << i - 1 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}