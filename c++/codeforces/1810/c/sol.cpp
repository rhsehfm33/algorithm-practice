#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    ll ans = c * a.size() + d;
    for (ll i = 0, d_sum = 0, c_sum = 0; i < a.size(); ++i) {
        if (i == 0) {
            d_sum += (a[i] - 1) * d;
        }
        else if (a[i] - a[i - 1] > 1) {
            d_sum += (a[i] - a[i - 1] - 1) * d;
        }
        while (i + 1 < a.size() and a[i + 1] == a[i]) {
            c_sum += c;
            ++i;
        }
        
        ll c_addition = (a.size() - i - 1) * c;
        ans = min(ans, d_sum + c_sum + c_addition);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}