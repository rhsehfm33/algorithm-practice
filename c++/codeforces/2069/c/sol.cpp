#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = 0, cur = 0, c1 = 0;
    for (auto& ai : a) {
        if (ai == 1) {
            ++cur;
            ++c1;
        } else if (ai == 2) {
            cur = (cur * 2) % MOD;
        } else {
            ans = (ans + cur) % MOD;
            ans = (ans - c1 + MOD) % MOD;
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