#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, mx = 0;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        mx = ai % 2 ? max(mx, ai) : mx;
    }

    if (mx == 0) {
        cout << "0\n";
        return;
    }

    ll ans = 0, e = 0;
    sort(a.begin(), a.end());
    for (auto& ai : a) {
        if (ai % 2 == 0) {
            if (ai > mx) {
                e = 1;
            }
            mx += ai;
            ++ans;
        }
    }
    cout << ans + e << '\n';
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