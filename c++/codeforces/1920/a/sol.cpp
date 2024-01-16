#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int mn = -1, mx = 2e9;

    int n;
    cin >> n;
    vector<int> ex;
    while (n--) {
        int a, x;
        cin >> a >> x;
        if (a == 1) {
            mn = max(mn, x);
        } else if (a == 2) {
            mx = min(mx, x);
        } else {
            ex.push_back(x);
        }
    }

    int ans = mx - mn + 1;
    for (auto exi : ex) {
        if (exi <= mx and exi >= mn) {
            --ans;
        }
    }
    cout << max(0, ans) << '\n';
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