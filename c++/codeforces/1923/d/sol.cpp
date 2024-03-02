#include <bits/stdc++.h>

using namespace std;

int _ti;

typedef long long ll;

const ll INF = 1e9;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1), as(n + 1), cs(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        as[i] = a[i] + as[i - 1];
        cs[i] = (a[i] != a[i - 1]) + cs[i - 1];
    }

    for (ll i = 1; i <= n; ++i) {
        if ((i > 1 and a[i - 1] > a[i]) or (i + 1 <= n and a[i + 1] > a[i])) {
            cout << "1 ";
            continue;
        }

        ll ans = INF, low = 0, high = i - 1;
        while (i > 1 and low <= high) {
            ll mid = (low + high) / 2;
            if (as[i - 1] - as[mid] > a[i] and cs[i - 1] != cs[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans = min(ans, (low == 0 ? INF : i - low));

        low = i + 1, high = n;
        while (i < n and low <= high) {
            ll mid = (low + high) / 2;
            if (as[mid] - as[i] > a[i] and cs[i + 1] != cs[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans = min(ans, (high == n ? INF : high + 1 - i));

        cout << (ans == INF ? -1 : ans) << ' ';
    }
    cout << '\n';
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