#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }

    set<ll> s;
    ll dup = 0;
    ll sum = (n + 1) * n / 2;
    for (ll i = 1; i < n; ++i) {
        ll diff = a[i] - a[i - 1];
        if (s.count(diff) or (diff) > n) {
            if (dup) {
                cout << "NO\n";
                return;
            }
            dup = diff;
        }
        else {
            sum -= diff;
            s.insert(diff);
        }
    }

    if (dup == 0 or dup == sum) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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