#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<array<ll, 2>> ax(n);
    for (auto& axi : ax) {
        cin >> axi[0];
    }
    for (auto& axi : ax) {
        cin >> axi[1];
    }
    sort(ax.begin(), ax.end(), [](auto& l, auto& r) {
        return abs(l[1]) < abs(r[1]);
    });

    for (ll i = 0, sum = 0; i < n; ++i) {
        sum += ax[i][0];
        if ((sum + k - 1) / k > abs(ax[i][1])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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