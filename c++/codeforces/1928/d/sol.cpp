#include <bits/stdc++.h>

using namespace std;

int _ti;

typedef long long ll;

ll get_sum(vector<ll>& c, ll x, ll b, ll k) {
    if (k == 1) {
        return 0;
    }
    
    ll s = 0;
    for (auto& ci : c) {
        ll p = ci * (ci - 1) / 2;
        p -= (ci % k) * (ci / k + 1) * (ci / k) / 2;
        p -= (k - ci % k) * (ci / k) * (ci / k - 1) / 2;
        s += p * b;
    }
    return s - ((k - 1) * x);
}

void solve() {
    ll n, b, x;
    cin >> n >> b >> x;
    vector<ll> c(n);
    for (auto& ci : c) {
        cin >> ci;
    }

    ll low = 1, high = *max_element(c.begin(), c.end()) - 1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll s1 = get_sum(c, x, b, mid);
        ll s2 = get_sum(c, x, b, mid + 1);
        if (s1 < s2) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << get_sum(c, x, b, low) << '\n';
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