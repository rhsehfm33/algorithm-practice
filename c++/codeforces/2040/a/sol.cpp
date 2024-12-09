#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> m;
    for (auto& ai : a) {
        cin >> ai;
        ++m[ai % k];
    }

    for (int i = 0; i < n; ++i) {
        if (m[a[i] % k] == 1) {
            cout << "YES\n" << i + 1 << '\n';
            return;
        }
    }
    cout << "NO\n";
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