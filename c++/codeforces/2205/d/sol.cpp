#include <bits/stdc++.h>
using namespace std;

int _ti;

void set_dp(vector<int>& a, vector<int>& dp) {
    vector<int> st = {a[0]};
    for (int i = 1; i + 1 < a.size(); ++i) {
        dp[i] = dp[i - 1];
        if (a[i] == max({a[i - 1], a[i], a[i + 1]})) {
            while (st.size() and st.back() < a[i]) {
                st.pop_back();
                ++dp[i];
            }
        }
        st.push_back(a[i]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int> ldp(n), rdp(n);
    set_dp(a, ldp);

    reverse(a.begin(), a.end());
    set_dp(a, rdp);
    reverse(rdp.begin(), rdp.end());

    int ans = 1e9;
    for (int i = 0; i + 1 < n; ++i) {
        ans = min(ans, ldp[i] + rdp[i + 1]);
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