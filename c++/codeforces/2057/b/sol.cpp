#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> a2c;
    while (n--) {
        int ai;
        cin >> ai;
        ++a2c[ai];
    }

    vector<int> c;
    for (auto [ai, ci] : a2c) {
        c.push_back(ci);
    }
    sort(c.begin(), c.end());
    
    int ans = c.size();
    for (auto ci : c) {
        if (k >= ci) {
            k -= ci;
            --ans;
        }
    }
    cout << max(1, ans) << '\n';
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