#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int> diff;
    for (int i = 0; i + 1 < n; ++i) {
        diff.push_back(abs(a[i] - a[i + 1]));
    }

    sort(diff.begin(), diff.end(), greater<int>());
    int ans = accumulate(diff.begin(), diff.end(), 0) - accumulate(diff.begin(), diff.begin() + k - 1, 0);
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