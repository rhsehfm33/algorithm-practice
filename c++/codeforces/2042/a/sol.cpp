#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.rbegin(), a.rend());

    int sum = 0;
    for (auto ai : a) {
        if (sum + ai > k) {
            break;
        }
        sum += ai;
    }
    cout << k - sum << '\n';
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