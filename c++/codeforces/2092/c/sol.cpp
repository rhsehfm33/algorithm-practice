#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

int _ti;

void solve() {
    ll n, oc = 0;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        oc += ai % 2;
    }
    if (oc == n or oc == 0) {
        cout << *max_element(a.begin(), a.end());
    } else {
        cout << accumulate(a.begin(), a.end(), 0ll) - (oc - 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
        cout << '\n';
    }

    return 0;
}