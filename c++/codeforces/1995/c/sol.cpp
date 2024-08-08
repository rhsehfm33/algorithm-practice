#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = 0;
    for (ll i = 1, pcnt = 0; i < n; ++i) {
        if (a[i] == 1 or a[i - 1] == 1) {
            if (a[i] < a[i - 1]) {
                cout << "-1\n";
                return;
            }
            continue;
        }

        ll cnt = 0;
        ll s = min(a[i], a[i - 1]);
        ll b = max(a[i], a[i - 1]);
        while (s * s <= b) {
            s *= s;
            ++cnt;
        }
        if (a[i] <= a[i - 1]) {
            cnt = pcnt + cnt + (s != b);
        } else {
            cnt = max(0ll, pcnt - cnt);
        }
        pcnt = cnt;
        ans += cnt;
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