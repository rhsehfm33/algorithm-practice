#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int c0 = 0, c1 = 0;
    int n;
    cin >> n;
    vector<char> a(n);
    for (auto& ai : a) {
        cin >> ai;
        if (ai == '1') {
            ++c1;
        }
    }

    int ans = -1;
    for (int i = 0; i <= n; ++i) {
        if (c0 >= (i + 1) / 2 and c1 >= (n - i + 1) / 2 and abs(n - ans * 2) > abs(n - i * 2)) {
            ans = i;
        }
        if (i < n and a[i] == '1') {
            --c1;
        } else {
            ++c0;
        }
    }
    cout << ans << '\n';
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