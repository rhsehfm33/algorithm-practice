#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    string ans{};
    for (int l = 0, r = n - 1; l < r; ++l, --r) {
        if (l % 2) {
            ans += (p[l] < p[r] ? "LR" : "RL");
        } else {
            ans += (p[l] > p[r] ? "LR" : "RL");
        }
    }
    if (n % 2) {
        ans += "L";
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