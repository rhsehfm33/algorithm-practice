#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> all_odds, all_evens;
ll f[45];

void preset() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= 44; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }

    vector<ll> odds, evens;
    for (int i = 1; i <= 44; ++i) {
        if (i % 2) {
            odds.push_back(f[i]);
        }
        else {
            evens.push_back(f[i]);
        }
    }

    for (int i = 0; i < (1 << odds.size()); ++i) {
        ll sum = 0;
        for (int j = 0; j < odds.size(); ++j) {
            if ((i >> j) & 1) {
                sum += odds[j];
            }
        }
        all_odds.push_back(sum);
    }

    for (int i = 0; i < (1 << evens.size()); ++i) {
        ll sum = 0;
        for (int j = 0; j < evens.size(); ++j) {
            if ((i >> j) & 1) {
                sum += evens[j];
            }
        }
        all_evens.push_back(sum);
    }
}

void solve(int _ti) {
    ll n, x, y;
    cin >> n >> x >> y;

    if (n % 2) {
        if (*lower_bound(all_odds.begin(), all_odds.end(), y - 1) == y - 1
        and *lower_bound(all_evens.begin(), all_evens.end(), x - 1) == x - 1) {
            cout << "YES\n";
            return;
        }
    }
    else {
        if (*lower_bound(all_evens.begin(), all_evens.end(), y - 1) == y - 1
        and *lower_bound(all_odds.begin(), all_odds.end(), x - 1) == x - 1) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    preset();
    
    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}