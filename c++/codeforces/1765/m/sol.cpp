#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            cout << n / i << ' ' << n - n / i << '\n';
            return;
        }
    }

    cout << 1 << ' ' << n - 1 << '\n';
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