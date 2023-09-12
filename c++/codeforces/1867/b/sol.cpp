#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int mis = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            ++mis;
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (i >= mis and i <= n - mis and (i % 2 == mis % 2 or n % 2)) {
            cout << "1";
        }
        else {
            cout << "0";
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