#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int x;
    cin >> x;

    int cx = 1;
    vector<int> ans = {1};
    for (int i = 0; i < 30; ++i) {
        if (cx + (1 << i) <= x) {
            cx += (1 << i);
            ans.push_back(cx);
        }
    }

    for (int i = 29; i >= 0; --i) {
        if (cx + (1 << i) <= x) {
            cx += (1 << i);
            ans.push_back(cx);
        }
    }

    
    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}