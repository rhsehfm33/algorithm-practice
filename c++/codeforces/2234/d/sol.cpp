#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, k;
    vector<string> s(3);
    cin >> n >> k >> s[0] >> s[1];
    for (int i = 0; i < n; ++i) {
        s[2] += (s[0][i] == s[1][i] ? '0' : '1');
    }
    vector<ll> cal(3);
    for (int i = 0; i < 3; ++i) {
        cal[i] = count(s[i].begin(), s[i].end(), '1');
        cal[i] *= (n - cal[i]);
    }

    ll ans = cal[0] + cal[1];
    map<array<int, 2>, ll> m;
    m[{0, 1}] = 1;
    while (k--) {
        map<array<int, 2>, ll> nm;
        for (auto [a, c] : m) {
            int t = 2;
            if (a[0] == 0 and a[1] == 2) {
                t = 1;
            } else if (a[0] == 1 and a[1] == 2) {
                t = 0;
            }
            ans += c * cal[t];
            nm[{min(a[0], t), max(a[0], t)}] += c;
            nm[{min(a[1], t), max(a[1], t)}] += c;
        }
        m = nm;
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