#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, s1, s2;
    cin >> n >> s1 >> s2;

    vector<array<ll, 2>> r(n);
    for (ll i = 0; i < n; ++i) {
        cin >> r[i][0];
        r[i][1] = i + 1;
    }
    sort(r.begin(), r.end(), greater<array<ll, 2>>());

    vector<ll> a, b;
    for (auto [cnt, color] : r) {
        if ((a.size() + 1) * s1 <= (b.size() + 1) * s2) {
            a.push_back(color);
        }
        else {
            b.push_back(color);
        }
    }

    cout << a.size() << ' ';
    for (auto ai : a) {
        cout << ai << ' ';
    }
    cout << '\n';

    cout << b.size() << ' ';
    for (auto bi : b) {
        cout << bi << ' ';
    }
    cout << '\n';
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