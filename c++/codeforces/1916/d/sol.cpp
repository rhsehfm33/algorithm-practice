#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }

    cout << "196" + string(n - 3, '0') + "\n";
    for (int i = 0; i < n / 2; ++i) {
        string z0 = string(i, '0');
        string z1 = string((n - 3) - (i * 2), '0');
        cout << "1" + z0 + "6" + z0 + "9" + z1 << '\n';
        cout << "9" + z0 + "6" + z0 + "1" + z1 << '\n';
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