#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_seven(ll num) {
    return to_string(num).find_first_of('7') != string::npos;
}

void solve(int _ti) {
    ll n;
    cin >> n;
    if (is_seven(n)) {
        cout << "0\n";
        return;
    }

    ll ans = 7;
    for (ll t = 9; t <= n * 10; t = t * 10 + 9) {
        for (ll i = 1, cn = n; i <= ans; ++i) {
            cn += t;
            if (is_seven(cn)) {
                ans = i;
                break;
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