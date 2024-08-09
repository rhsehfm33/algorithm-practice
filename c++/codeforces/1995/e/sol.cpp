#include <bits/stdc++.h>

using namespace std;

int _ti;

vector<int> lr;

void preset() {
    lr.resize(2e5 + 1);
    for (int i = 1; i <= 2e5; ++i) {
        int k = 0;
        for (int j = i; j > 0; j /= 3) {
            ++k;
        }
        lr[i] = lr[i - 1] + k;
    }
}

void solve() {
    int l, r, ans = 2e9;
    cin >> l >> r;
    for (int i = l; i <= min(r, l + 2); ++i) {
        int t = lr[i] - lr[i - 1];
        int s = lr[r] - lr[l - 1];
        ans = min(ans, t + s);
    }
    cout << ans << '\n';
}

int main() {
    preset();

    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}