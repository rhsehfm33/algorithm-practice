#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

bool isPossible(ll n, ll k) {
    --n;
     
    ll c = 1;
    while (n and c < k) {
        c *= 2;
        --n;
    }
    return c >= k;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    if (!isPossible(n, k)) {
        cout << "-1\n";
        return;
    }

    --k;
    vector<ll> l, r;
    for (ll i = n; i >= 1; --i) {
        ll p = n - 1 - i;
        if (p >= 0 and p <= (ll)log2(k) and (k & (1LL << p))) {
            r.push_back(i);
        } else {
            l.push_back(i);
        }
    }
    reverse(l.begin(), l.end());
    
    for (auto& li : l) {
        cout << li << ' ';
    }
    for (auto& ri : r) {
        cout << ri << ' ';
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