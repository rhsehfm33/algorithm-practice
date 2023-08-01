#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;

    vector<map<ll, ll>> ms(4);
    for (int i = 0; i < n; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        ++ms[0][xi];
        ++ms[1][yi];
        ++ms[2][xi - yi];
        ++ms[3][xi + yi];
    }

    ll ans = 0;
    for (auto m : ms) {
        for (auto [line, count] : m) {
            ans += (count * (count - 1));
        }
    }

    cout << ans << '\n';
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