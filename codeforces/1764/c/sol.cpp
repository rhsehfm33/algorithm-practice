#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        m[ai] += 1;
    }
    
    if (m.size() == 1) {
        cout << n / 2  << '\n';
        return;
    }

    vector<pair<ll, ll>> sa(m.begin(), m.end());
    ll ans = 0, ls = 0, rs = 0;
    for (auto& [ai, cnt] : sa) {
        rs += cnt;
    }
    
    for (int i = 0; i < sa.size() - 1; ++i) {
        ls += sa[i].se;
        rs -= sa[i].se;
        ans = max(ans, ls * rs);
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