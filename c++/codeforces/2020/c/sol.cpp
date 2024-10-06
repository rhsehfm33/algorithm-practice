#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll ans = 0, b, c, d; cin >> b >> c >> d;
    for (ll i = 0; i < 61; ++i) {
        ll di = 1LL << i;
        ll dd = d & di;
        ll cd = c & di;
        ll bd = b & di;
        if ((bd | di) - (cd & di) == dd) {
            ans |= di;
        } else if (bd != dd) {
            cout << "-1\n";
            return;
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