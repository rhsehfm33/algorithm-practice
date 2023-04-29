#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll go(ll k, ll d, ll& result) {
    if (d == 0) {
        return 1;
    }

    ll total = 0;
    ll smaller_total = go(k % d, d / 10, result);
    for (ll i = 0; i < 10; ++i) {
        if (i != 4) {
            total += smaller_total;
        }
    }

    for (ll i = 0; i < k / d; ++i) {
        if (i != 4) {
            result += smaller_total;
        }
    }

    return total;
}

void solve(int _ti) {
    ll k;
    cin >> k;

    if (k < 10) {
        cout << k + (k >= 4) << '\n';
        return;
    }

    ll low = 1;
    ll high = 1e18;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll result = 0;
        go(mid, pow(10, to_string(mid).size() - 1), result);
        
        if (result < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    string ans = to_string(low);

    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == '4') {
            ++ans[i];
        }
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