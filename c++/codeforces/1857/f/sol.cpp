#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

array<ll, 2> getTargets(ll mn, ll x, ll y) {
    ll low = mn;
    ll high = x / 2;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll mid2 = x - mid;
        if (mid * mid2 <= y) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return {low - 1, x - (low - 1)};
}

void solve(int _ti) {
    map<ll, ll> a2c;

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ++a2c[ai];
    }
    ll q;
    cin >> q;
    vector<array<ll, 2>> xy(q);
    for (int i = 0; i < q; ++i) {
        cin >> xy[i][0] >> xy[i][1];
    }

    ll mn = *min_element(a.begin(), a.end());
    for (auto [x, y] : xy) {
        auto [n1, n2] = getTargets(mn, x, y);
        if (n1 * n2 != y) {
            cout << 0 << ' ';
        }
        else {
            if (n1 == n2) {
                cout << a2c[n1] * (a2c[n1] - 1) / 2 << ' ';
            }
            else {
                cout << a2c[n1] * a2c[n2] << ' ';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}