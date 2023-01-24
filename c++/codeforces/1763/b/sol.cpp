#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    multiset<ll> msp;

    ll n, k;
    cin >> n >> k;
    vector<array<ll, 2>> hp(n);
    for (auto& hpi : hp) {
        cin >> hpi[0];
    }
    for (auto& hpi : hp) {
        cin >> hpi[1];
        msp.insert(hpi[1]);
    }
    sort(hp.begin(), hp.end());

    for (ll i = 0, sum = 0; i < n;) {
        while (sum < hp[i][0] and k > 0) {
            sum += k;
            k -= *msp.begin();
        }
        if (sum >= hp[i][0]) {
            k += *msp.begin();
            while (i < n and sum >= hp[i][0]) {
                msp.erase(msp.find(hp[i][1]));
                ++i;
            }
            k -= *msp.begin();
        }
        else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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