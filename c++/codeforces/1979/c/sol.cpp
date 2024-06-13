#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll klcm = 1;

    ll n;
    cin >> n;
    vector<ll> k(n);
    for (auto& ki : k) {
        cin >> ki;
        klcm = lcm(klcm, ki);
    }

    vector<ll> ans;
    for (auto& ki : k) {
        ans.push_back(klcm / ki);
    }

    if (accumulate(ans.begin(), ans.end(), 0ll) >= klcm) {
        cout << "-1\n";
        return;
    }
     
    for (auto& ansi : ans) {
        cout << ansi << ' ';
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