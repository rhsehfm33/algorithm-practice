#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m;
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> apq;
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        apq.push(ai);
    }

    for (int i = 0; i < m; ++i) {
        ll bi;
        cin >> bi;
        apq.pop();
        apq.push(bi);
    }

    ll ans = 0;
    while (apq.size()) {
        ans += apq.top(); apq.pop();
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