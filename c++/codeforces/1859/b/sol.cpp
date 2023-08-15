#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<vector<ll>> a(n);
    for (auto& ai : a) {
        int mi;
        cin >> mi;
        ai.resize(mi);
        for (auto& aij : ai) {
            cin >> aij;
        }
        sort(ai.begin(), ai.end());
    }

    ll sum = 0, mn0 = 2e9, mn1 = 2e9;
    for (auto& ai : a) {
        sum += ai[1];
        mn0 = min(mn0, ai[0]);
        mn1 = min(mn1, ai[1]);
    }

    cout << sum - mn1 + mn0 << '\n';
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