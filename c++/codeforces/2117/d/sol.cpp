#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    if (a[n - 1] < a[0]) {
        reverse(a.begin(), a.end());
    }

    int d = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
        if (d != a[i] - a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    if (a[0] - d >= 0 and (a[0] - d) % (n + 1) == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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