#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;

int _ti;

int cal2(int n, int r) {
    int ans = 0;
    string sn = to_string(n);
    for (int i = 0; i < r; ++i) {
        ans = ans * 10 + (sn[i % sn.size()] - '0');
    }
    return ans;
}

void solve() {
    vector<array<int, 2>> ans;

    int n;
    cin >> n;
    int ns = to_string(n).size();
    for (int a = 1; a <= MAX; ++a) {
        for (int i = 1; i <= 6; ++i) {
            int t = cal2(n, i);
            int b = a * n - t;
            if (b > 0 and b <= MAX and a * ns - b == i) {
                ans.push_back({a, b});
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto& [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }
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