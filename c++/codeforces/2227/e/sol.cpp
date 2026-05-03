#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll sum = 0;
    vector<ll> mn(n + 1, 1e9);
    for (ll i = n - 1; i >= 0; --i) {
        sum += max(0LL, a[i] - mn[i + 1]);
        mn[i] = min(mn[i + 1], a[i]);
    }

    ll ans = sum;
    stack<array<ll, 2>> st;
    for (int i = 0; i < n; ++i) {
        ll cnt = 0;
        while (st.size() and a[i] <= st.top()[0]) {
            cnt += st.top()[1];
            st.pop();
        }
        if (a[i] <= mn[i]) {
            ans = max(ans, sum + cnt);
        }
        st.push({a[i], cnt + 1});
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