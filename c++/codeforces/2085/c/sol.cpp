#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

int _ti;

void solve() {
    ll x, y, k = 0;
    cin >> x >> y;
    for (ll i = 1; i <= (1LL << 40); i <<= 1) {
        if ((x & i) & (y & i)) {
            if ((x & (i - 1)) == (y & (i - 1))) {
                k += i;
                x += i;
                y += i;
                continue;
            }
            for (ll j = i; j; j >>= 1) {
                if (!((x & j) & (y & j))) {
                    k += j;
                    x += j;
                    y += j;
                    if ((x & j) ^ (y & j)) {
                        break;
                    }
                }
            }
        }
    }
    cout << ((x & y) ? -1 : k) << '\n';
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