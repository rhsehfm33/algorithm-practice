#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    vector<int> b(n);
    for (auto& bi : b) {
        cin >> bi;
    }

    int ans = 0;
    map<int, int> ma;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n and a[i] == a[j]) {
            ++j;
        }
        ans = max(ans, ma[a[i]] = max(ma[a[i]], j - i));
        i = j - 1;
    }

    map<int, int> mb;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n and b[i] == b[j]) {
            ++j;
        }
        ans = max(ans, mb[b[i]] = max(mb[b[i]], j - i));
        i = j - 1;
    }

    for (auto [num, cnt] : ma) {
        if (mb.count(num)) {
            ans = max(ans, cnt + mb[num]);
        }
    }
    cout << ans << '\n';
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