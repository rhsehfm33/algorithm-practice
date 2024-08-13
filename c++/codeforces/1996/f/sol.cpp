#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

array<ll, 2> cal(ll ai, ll bi, ll t) {
    ll cnt = (ai - t + bi - 1) / bi;
    ll added = (cnt * ai) - (bi * cnt * (cnt - 1) / 2);
    return {cnt, added};
}

void solve() {
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    ll low = 1, high = 1e9;
    while (low <= high) {
        ll ck = k, sum = 0;
        ll mid = (low + high) / 2;

        vector<ll> na = a;
        for (ll i = 0; i < n and ck >= 0; ++i) {
            if (na[i] <= mid) {
                continue;
            }
            auto [mk, added] = cal(na[i], b[i], mid);
            sum += added;
            ck -= mk;
            na[i] = max(0LL, na[i] - b[i] * mk);
        }

        sort(na.rbegin(), na.rend());
        for (ll i = 0; i < n and ck > 0; ++i, --ck) {
            sum += na[i];
        }

        if (ck < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
            ans = max(ans, sum);
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