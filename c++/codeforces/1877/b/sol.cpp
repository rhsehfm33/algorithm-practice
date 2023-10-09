#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, p;
    cin >> n >> p;
    vector<array<ll, 2>> ba(n);
    for (int i = 0; i < n; ++i) {
        cin >> ba[i][1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> ba[i][0];
    }
    ba.push_back({p, (ll)2e5});

    sort(ba.begin(), ba.end());

    ll sum = p;
    for (ll i = 0, c = 0; c < n - 1; ++i) {
        sum += min(n - 1 - c, ba[i][1]) * ba[i][0];
        c += min(n - 1 - c, ba[i][1]);
    }

    cout << sum << '\n';
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