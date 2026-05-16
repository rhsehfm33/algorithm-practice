#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ordered_set = tree<pair<ll,ll>, null_type, less<pair<ll,ll>>,
            rb_tree_tag, tree_order_statistics_node_update>;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ordered_set os;
    os.insert({a[1], 1});
    for (ll i = 2, cur = 0; i <= n; ++i) {
        cur -= a[i];
        os.insert({a[i] + cur, i});
    }

    int ti = 0;
    vector<int> ans(n + 1);
    for (auto [v, i] : os) {
        ans[i] = ++ti;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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