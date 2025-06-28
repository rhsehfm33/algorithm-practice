#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int _ti;

void solve() {
    vector<ll> ans;
    ll n, m;
    cin >> n >> m;
    if (m > n * (n + 1) / 2 or m < n) {
        cout << "-1\n";
        return;
    }

    vector<bool> vis(n + 1);
    ll i = n;
    while (true) {
        if (m > i + i - 1) {
            vis[i] = true;
            ans.push_back(i);
            m -= i;
            --i;
        } else {
            --i;
            ans.push_back(m - i);
            vis[m - i] = true;
            m -= (m - i);
            break;
        }
    }

    for (int j = 1; j <= n; ++j) {
        if (!vis[j]) {
            ans.push_back(j);
        }
    }

    cout << ans[0] << '\n';
    for (int j = 0; j < n - 1; ++j) {
        cout << ans[j] << ' ' << ans[j + 1] << '\n';
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