#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, x;
    cin >> n >> x;
    int sor = 0;
    vector<int> ans;
    for (int i = 0; ans.size() < n; ++i) {
        if ((i | x) > x) {
            break;
        }
        sor |= i;
        ans.push_back(i);
    }
    while (ans.size() < n) {
        sor = x;
        ans.push_back(x);
    }
    if (sor != x) {
        ans.pop_back();
        ans.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
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