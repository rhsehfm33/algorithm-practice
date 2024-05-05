#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll ans = 0;
    string s;
    cin >> s;
    for (ll i = 0, c1 = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            ++c1;
        } else if (c1) {
            ans += c1 + 1;
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