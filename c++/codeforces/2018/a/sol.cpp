#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    ll mx = *max_element(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);

    for (ll i = n; i >= 1; --i) {
        ll dc = (sum + k) / i;
        if (sum <= dc * i and mx <= dc) {
            cout << i << '\n';
            return;
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