#include <bits/stdc++.h>
using namespace std;
 
int _ti;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1);
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ++cnt[ai];
    }
 
    int ki = 0;
    vector<int> ans1;
    for (int i = 1; i <= n and ans1.size() < k; ++i) {
        if (!cnt[i]) {
            ans1.push_back(i);
        }
    }

    vector<int> ans2;
    for (int i = n - 1; i >= 0; --i) {
        if (cnt[a[i]] != -1) {
            cnt[a[i]] = -1;
            ans2.push_back(a[i]);
        }
    }
    reverse(ans2.begin(), ans2.end());
    ans1.insert(ans1.end(), ans2.begin(), ans2.end());
    for (int i = 0; i < k; ++i) {
        cout << ans1[i] << ' ';
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