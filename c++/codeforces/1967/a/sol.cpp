#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll low = 0, high = 1e13;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll ck = k, o = 0;
        for (ll i = 0; i < n and ck >= 0; ++i) {
            if (a[i] > mid) {
                ++o;
            } else {
                ck -= mid - a[i];
            }
        }
        if (ck < 0) {
            high = mid - 1;
        } else {
            if (o + ck < n) {
                cout << mid * n - n + 1 + o + ck << '\n';
                return;
            } else {
                low = mid + 1;
            }
        }
    }
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