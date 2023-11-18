#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = -10000;
    for (int i = 0, sum = 0, prv = a[0] + 1; i < n; ++i) {
        if ((prv + a[i]) & 1) {
            sum += a[i];
        } else {
            sum = a[i];
        }
        ans = max(ans, sum);
        
        if (sum < 0) {
            sum = 0;
            prv = i + 1 < n ? a[i + 1] + 1 : 0;
        } else {
            prv = a[i];
        }
    }
    cout << ans << '\n';
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