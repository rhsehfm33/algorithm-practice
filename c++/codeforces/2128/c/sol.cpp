#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto& bi : b) {
        cin >> bi;
    }
    for (int i = 1, mn = b[0]; i < n; ++i) {
        if (mn < b[i] / 2 + 1) {
            cout << "NO\n";
            return;
        }
        mn = min(mn, b[i]);
    }
    cout << "YES\n";
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