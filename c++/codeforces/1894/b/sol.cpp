#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    map<int, int> m;

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ++m[ai];
    }

    int mc = 0;
    for (auto [ai, cnt] : m) {
        if (cnt > 1) {
            ++mc;
        }
    }

    if (mc < 2) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (m[a[i]] > 1) {
            if (--mc == 0) {
                cout << 3 << ' ';
            } else {
                cout << 2 << ' ';
            }
            m[a[i]] = 0;
        } else {
            cout << 1 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}