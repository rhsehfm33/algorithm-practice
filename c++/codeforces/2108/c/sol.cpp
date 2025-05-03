#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, ans = 1;
    cin >> n;
    vector<int> a;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        if (a.empty() or a.back() != ai) {
            a.push_back(ai);
        }
    }

    for (int i = 1; i + 1 < a.size(); ++i) {
        ans += (a[i - 1] > a[i] and a[i + 1] > a[i]);
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