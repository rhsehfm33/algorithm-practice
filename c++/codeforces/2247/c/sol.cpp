#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }
    array<int, 2> t{}, f{};
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            ++f[a[i]];
        } else {
            ++t[a[i]];
        }
    }
    if (f[0] + f[1] == 0) {
        cout << "0\n";
    } else if (f[1]) {
        cout << (f[1] % 2 ? 1 : 2) << '\n';
    } else {
        cout << (t[0] and t[1] ? 2 : -1) << '\n';
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