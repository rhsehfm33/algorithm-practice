#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

bool isLeftBigger(ll num1, ll num2) {
    for (ll i = 10; num1 % i == 0 or num2 % i == 0; i *= 10) {
        if (num1 % i != 0) {
            return false;
        }
        else if (num2 % i != 0) {
            return true;
        }
    }

    return num1 > num2;
}

void solve(int _ti) {
    ll n, m;
    cin >> n >> m;

    ll ans = n * m;
    ll p = 10;
    while (true) {
        ll cgcd = lcm(n, p);
        if (cgcd <= n * m) {
            ll curResult = n * m - ((n * m) % cgcd);
            if (isLeftBigger(curResult, ans)) {
                ans = curResult;
            }
        }
        else {
            break;
        }
        p *= 10;
        if (cgcd >= (ll)1e18) {
            break;
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