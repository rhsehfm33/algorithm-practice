#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    set<array<int, 2>> s;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n and a[i] == a[j]) {
            ++j;
        }
        s.insert({-i, j - 1});
        i = j - 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        --i;
        --j;
        auto [si, sj] = *s.lower_bound(array<int, 2>({-i, -1234567}));
        if (sj >= j) {
            cout << -1 << ' ' << -1 << '\n';
        } else {
            cout << i + 1 << ' ' << sj + 2 << '\n';
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