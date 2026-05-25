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

    int lb = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            lb = max(lb, a[i] - a[i + 1]);
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            a[i + 1] += lb;
        }
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");
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