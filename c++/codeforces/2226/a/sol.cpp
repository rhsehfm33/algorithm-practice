#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        if (ai > 1) {
            ans += ai;
        }
    }
    ans += (a.back() == 1);
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