#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, ld;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }
    cin >> m;
    map<int, int> d;
    while (m--) {
        int di;
        cin >> di;
        if (m == 0) {
            ld = di;
        }
        ++d[di];
    }

    int di = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i] and d[b[i]]-- <= 0) {
            cout << "NO\n";
            return;
        }
    }
    
    if (find(b.begin(), b.end(), ld) == b.end()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";    
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