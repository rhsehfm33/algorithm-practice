#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll a, b, r;
    cin >> a >> b >> r;
    if (b > a) {
        swap(a, b);
    }

    bool isf = true;
    ll ans = a - b;
    for (ll i = 60; i >= 0; --i) {
        ll a1 = ((a >> i) & 1);
        ll b1 = ((b >> i) & 1);
        if (a1 ^ b1) {
            if (isf) {
                isf = false;
            } else if (a1 and r - (1LL << i) >= 0) {
                ans -= (1LL << i) * 2;
                r -= (1LL << i);
            }
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