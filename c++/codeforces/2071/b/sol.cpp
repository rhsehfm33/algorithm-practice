#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

bool is_sqr(ll num) {
    ll root = static_cast<ll>(sqrtl(num));
    return root * root == num;
}

void solve() {
    ll n;
    cin >> n;
    set<ll> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
    }

    ll sum = 0;
    vector<ll> ans;
    while (s.size()) {
        if (is_sqr(sum + *s.begin())) {
            if (s.size() == 1) {
                cout << -1 << '\n';
                return;
            }
            ans.push_back(*next(s.begin()));
            sum += *next(s.begin());
            s.erase(next(s.begin()));
        } else {
            ans.push_back(*s.begin());
            sum += *s.begin();
            s.erase(s.begin());
        }
    }
    for (int i = 0; i < n; ++i) {
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