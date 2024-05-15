#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll l = 0, r = n - 1;
    while (l <= r) {
        ll mn = min(a[l], a[r]);
        if (k >= 2 * mn and l < r) {
            a[l] -= mn;
            a[r] -= mn;
            k -= mn * 2;
        } else {
            if ((l == r and k >= a[l]) or (k == 2 * a[l] - 1)) {
                ++l;
            }
            break;
        }

        if (a[l] == 0) {
            ++l;
        }
        if (a[r] == 0) {
            --r;
        }
    }

    cout << n - (r - l + 1) << '\n';
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