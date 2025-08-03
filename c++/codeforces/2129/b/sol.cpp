#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    ll ans = 0;
    ordered_set<ll> os;
    for (int i = 0; i < n; ++i) {
        ll lhigh = i - os.order_of_key(p[i]);
        ll rhigh = (n - p[i]) - lhigh;
        ans += min(lhigh, rhigh);
        os.insert(p[i]);
    }
    cout << ans << '\n';
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