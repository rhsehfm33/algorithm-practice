#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll mx = *max_element(a.begin(), a.end());
    ll mn = *min_element(a.begin(), a.end());
    if (mx == mn) {
        cout << n * n - n << '\n';
        return;
    }

    ll mxc = 0, mnc = 0;
    for (auto& ai : a) {
        if (ai == mx) {
            ++mxc;
        }
        else if (ai == mn) {
            ++mnc;
        }
    }

    cout << mxc * mnc * 2 << '\n';
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