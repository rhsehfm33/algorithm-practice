#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = 0, sum = a[0];
    for (int i = 1; i < n; ++i) {
        if (sum == 0) {
            ++ans;
            sum = a[i];
            continue;
        }
        sum &= a[i];
    }

    if (sum == 0) {
        ++ans;
    }

    cout << max(1, ans) << '\n';
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