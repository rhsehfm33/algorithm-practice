#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> e, o;
    for (ll i = 0, ai; i < n; ++i) {
        cin >> ai;
        if (ai % 2) {
            o.push_back(ai);
        } else {
            e.push_back(ai);
        }
    }
    sort(o.begin(), o.end(), greater<int>());
    sort(e.begin(), e.end(), greater<int>());
    if (o.empty()) {
        for (int i = 0; i < n; ++i) {
            cout << "0 ";
        }
        cout << '\n';
        return;
    }
    if (e.empty()) {
        for (int i = 0; i < n; ++i) {
            cout << (i % 2 == 0 ? o[0] : 0) << ' ';
        }
        cout << '\n';
        return;
    }

    for (ll i = 0, es = 0, ei = 0; i < n; ++i) {
        if (ei < e.size()) {
            cout << es + o[0] << ' ';
        } else {
            if ((i + 1 - ei) % 2) {
                cout << es + o[0] << ' ';
            } else {
                if (i == n - 1) {
                    cout << "0 ";
                } else {
                    cout << es - e.back() + o[0] << ' ';
                }
            }
        }
        if (ei < e.size()) {
            es += e[ei++];
        }
    }
    cout << '\n';
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