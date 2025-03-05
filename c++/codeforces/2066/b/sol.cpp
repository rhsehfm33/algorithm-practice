#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    set<int> ab;
    for (int i = 1; i <= n; ++i) {
        ab.insert(i);
    }

    int ans = 0;
    map<int, int> ai2c;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        if (++ai2c[ai] == 1 and ai > 0) {
            ab.erase(ai);
        }
        ans += ai > 0;
    }
    
    if (ai2c[0] == 0) {
        cout << ans << '\n';
        return;
    }
    
    for (int i = 0, mn = 2e9; i < n; ++i) {
        if (a[i]) {
            if (--ai2c[a[i]] == 0) {
                ab.insert(a[i]);
            }
            mn = min(mn, a[i]);
        } else {
            ++ans;
            break;
        }
        if (mn < *ab.begin()) {
            break;
        }
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