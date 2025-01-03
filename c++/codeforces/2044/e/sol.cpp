#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ck = k, ans = max(0ll, min(r1, r2) - max(l1, l2) + 1);
    while (ck <= r2) {
        ans += max(0ll, min(r1, (r2 / ck)) - max(l1 - 1, ((l2 - 1) / ck)));
        ck *= k;
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