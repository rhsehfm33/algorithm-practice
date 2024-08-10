#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto& bi : b) {
        cin >> bi;
    }

    a[0] = b.front();
    a[n - 1] = b.back();
    for (int i = 1; i < n - 1; ++i) {
        a[i] = b[i - 1] | b[i];
        if (b[i - 1] != (a[i - 1] & a[i])) {
            cout << "-1\n";
            return;
        }
    }

    for (auto& ai : a) {
        cout << ai << ' ';
    }
    cout << '\n';
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