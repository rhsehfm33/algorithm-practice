#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    map<int, int> m;
    int n;
    cin >> n;
    while (n--) {
        int ai;
        cin >> ai;
        ++m[ai];
    }

    for (auto& [num, cnt] : m) {
        if (cnt % 2) {
            cout << "YES\n";
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