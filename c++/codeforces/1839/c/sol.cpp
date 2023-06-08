#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int c1 = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ++c1;
        }
        else {
            ans.push_back(c1);
            while (c1--) {
                ans.push_back(0);
            }
            c1 = 0;
        }
    }

    if (c1 > 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = n - 1; i >= 0; --i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}