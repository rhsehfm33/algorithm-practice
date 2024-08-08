#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    array<int, 4> cnt{0,};
    int n;
    cin >> n;
    int ans = 4 * n;
    for (int i = 0; i < 4 * n; ++i) {
        char ch;
        cin >> ch;
        if (ch != '?') {
            ++cnt[ch - 'A'];
        } else {
            --ans;
        }
    }

    for (int i = 0; i < 4; ++i) {
        ans -= max(0, cnt[i] - n);
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