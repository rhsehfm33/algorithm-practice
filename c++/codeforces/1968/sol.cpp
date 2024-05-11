#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll getMax(vector<ll>& p, vector<ll>& a, ll x, ll k) {
    ll result = 0, sum = 0;
    vector<bool> vis(p.size());
    while (!vis[x] and k--) {
        result = max(result, sum + a[x] * (k + 1));
        sum += a[x];
        vis[x] = true;
        x = p[x];
    }
    return result;
}

void solve() {
    ll n, k, Pb, Ps;
    cin >> n >> k >> Pb >> Ps;
    vector<ll> p(n + 1), a(n + 1);
    for (int i = 1 ; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1 ; i <= n; ++i) {
        cin >> a[i];
    }

    ll bm = getMax(p, a, Pb, k);
    ll sm = getMax(p, a, Ps, k);
    if (bm > sm) {
        cout << "Bodya\n";
    } else if (sm > bm) {
        cout << "Sasha\n";
    } else {
        cout << "Draw\n";
    }
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