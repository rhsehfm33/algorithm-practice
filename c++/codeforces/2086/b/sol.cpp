#include <bits/stdc++.h>

using namespace std;

int _ti;

typedef long long ll;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    vector<ll> ps(n + 1);
    for (ll i = 1; i <= n; ++i) {
        ps[i] = a[i - 1] + ps[i - 1];
    }

    ll low = 0, high = n * k;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll d = mid / n;
        ll r = mid % n;
        ll csum = d * sum + ps[r];
        if (k * sum - csum >= x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << low << '\n';
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