#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_max(vector<ll> cases) {
    return *max_element(cases.begin(), cases.end());
}

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll ans = accumulate(a.begin(), a.end(), 0ll);
    if (n == 2) {
        ans = max(ans, abs(a[0] - a[1]) * 2);
    }
    else if (n == 3) {
        ll dif01 = abs(a[0] - a[1]);
        ll dif12 = abs(a[1] - a[2]);
        ll case1 = max(a[0] * 3, a[2] * 3);
        ll case2 = max(a[0] + dif12 * 2, a[2] + dif01 * 2);
        ll case3 = max(dif01 * 3, dif12 * 3);
        ans = get_max({ans, case1, case2, case3});
    }
    else {
        ans = *max_element(a.begin(), a.end()) * n;
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