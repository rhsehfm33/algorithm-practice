#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int l, r, L, R, ans = 0;
    cin >> l >> r >> L >> R;
    if (l > L) {
        swap(l, L);
        swap(r, R);
    }
    if (r < L) {
        cout << 1 << '\n';
        return;
    }

    if (l != L) {
        ++ans;
    }
    if (r != R) {
        ++ans;
    }
    ans += max(0, min(r, R) - max(l, L));
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