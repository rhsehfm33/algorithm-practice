#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll low = 1, high = 2e9;
    while (low <= high) {
        ll sum = 0;
        ll mid = (low + high) / 2;
        for (ll i = 0; i < n; ++i) {
            sum += max(mid - a[i], 0ll);
        }

        if (sum <= x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << low - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}