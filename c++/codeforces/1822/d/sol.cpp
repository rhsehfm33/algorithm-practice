#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    if (n == 1) {
        cout << n << '\n';
    }
    else if (n % 2 == 1) {
        cout << -1 << '\n';
    }
    else {
        cout << n << ' ';
        for (int i = 1, odd = n - 1, even = 2; i < n; ++i) {
            if (i % 2) {
                cout << odd << ' ';
                odd -= 2;
            }
            else {
                cout << even << ' ';
                even += 2;
            }
        }

        cout << '\n';
    }
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