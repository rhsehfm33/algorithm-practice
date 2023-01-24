#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;
    ll ans = 1;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ans *= ai;
    }

    cout << (ans + n - 1) * 2022 << '\n';
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