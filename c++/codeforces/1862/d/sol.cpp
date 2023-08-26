#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    ll low = 1, high = 2e9;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll sum = mid * (mid - 1) / 2;
        if (sum <= n) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    ll ans = low - 1;
    ans += (n - (ans * (ans - 1) / 2));

    cout << ans;
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