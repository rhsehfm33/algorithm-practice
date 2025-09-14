#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll k, x;
    cin >> k >> x;
    ll cx = (1LL << (k + 1)) - x;
    vector<int> ans;
    while (cx != x) {
        if (cx > x) {
            cx -= x;
            x += x;
            ans.push_back(1);
        } else {
            x -= cx;
            cx += cx;
            ans.push_back(2);
        }
    }

    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; --i) {
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