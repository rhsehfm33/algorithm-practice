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

    for (int i = 0; i < n; ++i) {
        if (a[i] <= i * 2 or a[i] <= (n - i - 1) * 2) {
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