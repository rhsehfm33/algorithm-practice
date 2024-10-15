#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int _ti;

void solve() {
    int n, r, oc = 0, sum = 0;
    cin >> n >> r;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        oc += ai % 2;
        sum += ai;
    }

    cout << sum - max(0, sum + oc - r * 2) << '\n';
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