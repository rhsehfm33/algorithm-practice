#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, c0 = 0, c1 = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' and (!i or s[i - 1] == '1')) {
            ++c0;
        } else if (s[i] == '1') {
            ++c1;
        }
    }

    if (c0 < c1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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