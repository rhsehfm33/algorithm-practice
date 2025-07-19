#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

struct s01 {
    ll c = 0;
    ll sum[2]{};

    s01& operator+=(const s01& rhs) {
        c += rhs.c;
        sum[0] += rhs.sum[0];
        sum[1] += rhs.sum[1];
        return *this;
    }

    s01& operator-=(const s01& rhs) {
        c -= rhs.c;
        sum[0] -= rhs.sum[0];
        sum[1] -= rhs.sum[1];
        return *this;
    }
};

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    ll c[2]{};
    s01 all[2];
    stack<s01> st[2];
    for (ll i = 0; i < n; ++i) {
        int d = s[i] - '0';
        int cd = d ^ 1;

        s01 cur;
        cur.c = 1;
        cur.sum[0] = c[0];
        cur.sum[1] = c[1];
        if (st[cd].size()) {
            all[cd] -= st[cd].top();
            cur += st[cd].top();
            st[cd].pop();
        }
        all[d] += cur;
        st[d].push(cur);
        ++c[d];

        ans += all[d].c * c[d] - all[d].sum[d];
        ans += all[cd].c * c[cd] - all[cd].sum[cd];
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