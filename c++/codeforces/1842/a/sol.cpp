#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);

    for (ll& ai : a) {
        cin >> ai;
    }
    for (ll& bi : b) {
        cin >> bi;
    }

    ll aSum = accumulate(a.begin(), a.end(), 0ll);
    ll bSum = accumulate(b.begin(), b.end(), 0ll);
    if (aSum > bSum) {
        cout << "Tsondu" << '\n';
    }
    else if (bSum > aSum) {
        cout << "Tenzing" << '\n';
    }
    else {
        cout << "Draw" << '\n';
    }
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