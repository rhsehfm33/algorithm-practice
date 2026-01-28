#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ans;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        while (i < n and s[i] == '0') {
            ++i;
        }
        while (j >= 0 and s[j] == '1') {
            --j;
        }
        if (i < j) {
            ans.push_back(i);
            ans.push_back(j);
        }
    }
    if (ans.empty()) {
        cout << "Bob\n";
        return;
    }

    cout << "Alice\n";
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << ' ';
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