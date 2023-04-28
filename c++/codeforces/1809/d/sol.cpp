#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll COST1 = 1e12;
ll COST2 = 1e12 + 1;

void solve(int _ti) {
    string s;
    cin >> s;

    ll c1 = 0;
    for (ll i = 0; i < s.size(); ++i) {
        c1 += s[i] == '1';
    }

    ll ans = c1 * COST2;
    ll c0 = 0;
    for (ll r = s.size() - 1; r >= 0; --r) {
        ll l = r;
        while (l >= 0 and s[l] == '0') {
            --l;
        }
        if (l < 0) {
            break;
        }

        c1 -= 1;
        ans = min(ans, (r - l) * COST1 + (c1 + c0) * COST2);
        c0 += (r - l);
        r = l;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}