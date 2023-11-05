#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<vector<ll>>> vvvi;

void help(vvvi& c, string& s) {
    for (ll i = s.size() + 1; i <= s.size() + 5; ++i) {
        if (i % 2) {
            continue;
        }

        ll sum = 0;
        for (ll j = 0; j < s.size(); ++j) {
            if (j < i / 2) {
                sum += s[j] - '0';
            } else {
                sum -= s[j] - '0';
            }
        }
        if (sum < 0) {
            continue;
        }
        ++c[i][s.size()][sum];
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vvvi lc(11, vvi(6, vi(50)));
    vvvi rc(11, vvi(6, vi(50)));
    for (ll i = 0; i < n; ++i) {
        help(lc, s[i]);
        reverse(s[i].begin(), s[i].end());
        help(rc, s[i]);
    }

    ll ans = 0;
    for (ll i = 2; i <= 10; i += 2) {
        for (ll j = 1; j <= i - 1; ++j) {
            for (ll k = 1; k <= 45; ++k) {
                if (j > 5 or i - j > 5 or j < 1 or i - j < 1) {
                    continue;
                }
                ans += lc[i][j][k] * rc[i][i - j][k];
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}