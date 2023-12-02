#include <bits/stdc++.h>
 
using namespace std;
 
void solve(int _ti) {
    int mn = 2e9, mx = -1;
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        mn = min(mn, ai);
        mx = max(mx, ai);
    }
 
    vector<int> ans;
    while (mn < mx) {
        if (mn % 2) {
            mn = (mn + 1) / 2;
            mx = (mx + 1) / 2;
            ans.push_back(1);
        } else {
            mn /= 2;
            mx /= 2;
            ans.push_back(0);
        }
    }
 
    cout << ans.size() << '\n';
    if (ans.size() <= n and ans.size()) {
        for (auto& ansi : ans) {
            cout << ansi << ' ';
        }
        cout << '\n';
    }
 
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