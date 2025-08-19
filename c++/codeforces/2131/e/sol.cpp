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
    if (a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    }

    for (int i = n - 2; i >= 0; --i) {
        if (a[i] != b[i]
        and (a[i] ^ a[i + 1]) != b[i]
        and (a[i] ^ b[i + 1]) != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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