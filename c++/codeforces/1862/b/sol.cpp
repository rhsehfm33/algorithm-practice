#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto& bi : b) {
        cin >> bi;
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (ans.size() and ans.back() > b[i]) {
            ans.push_back(1);
        }
        ans.push_back(b[i]);
    }

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