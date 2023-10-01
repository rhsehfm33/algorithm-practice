#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    array<ll, 2> sum = {0, 0};

    ll n, m, k;
    cin >> n >> m >> k;
    vector<multiset<ll>> ms(2);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        ms[0].insert(ai);
        sum[0] += ai;
    }
    for (ll i = 0; i < m; ++i) {
        ll bi;
        cin >> bi;
        ms[1].insert(bi);
        sum[1] += bi;
    }
    
    --k;
    for (ll i = 0, ps = -1, pb = -1; i <= k; ++i) {
        ll s = *ms[i & 1].begin();
        ll b = *prev(ms[(i & 1) ^ 1].end());
        if (b - s < 0) {
            continue;
        }

        ms[i & 1].insert(b);
        ms[i & 1].erase(ms[i & 1].find(s));
        ms[(i & 1) ^ 1].insert(s);
        ms[(i & 1) ^ 1].erase(ms[(i & 1) ^ 1].find(b));
        sum[i & 1] += (b - s);
        sum[(i & 1) ^ 1] += (s - b);

        if (i % 2 == k % 2 and s == ps and b == pb) {
            break;
        }
        ps = s;
        pb = b;
    }

    cout << sum[0] << '\n';
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