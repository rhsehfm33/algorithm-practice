#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    vector<int> ans = {1};
    for (int i = 1, mxi = 0; i < n; ++i) {
        if (a[mxi] - a[i] == b[mxi] - b[i]) {
            ans.push_back(i + 1);
        }
        else if (a[mxi] - a[i] < b[mxi] - b[i]) {
            mxi = i;
            ans.clear();
            ans.push_back(mxi + 1);
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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