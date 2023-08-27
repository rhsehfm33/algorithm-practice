#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 1, sum = 0; i <= n; ++i) {
        if (a[i] <= 0) {
            continue;
        }

        pq.push(a[i]);
        sum += a[i];
        if (pq.size() > m) {
            sum -= pq.top();
            pq.pop();
        }
        ans = max(ans, sum - i * d);
    }

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