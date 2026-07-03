#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, x = 0;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        x ^= ai;
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    if (x == 0) {
        cout << "1\n";
        return;
    }

    int ans = 0;
    int msb = 31 - __builtin_clz(x);
    for (auto ai : a) {
        if (ai & (1 << msb)) {
            ++ans;
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