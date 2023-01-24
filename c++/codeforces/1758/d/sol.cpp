#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = n - n / 2; i <= n + n / 2; ++i) {
            if (i == n) {
                continue;
            }
            cout << i << ' ';
        }
        cout << '\n';
    }
    else {
        n += 1;
        for (int i = n - n / 2 + 1; i <= n + n / 2 + 1; ++i) {
            if (i == n or i == n + 1) {
                continue;
            }
            cout << i << ' ';
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