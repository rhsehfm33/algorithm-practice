#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 2; i <= n / 2; ++i) {
        vector<int> cnt(i);
        for (int j = 0; j < n; ++j) {
            ++cnt[a[j] % i];
        }
        int mn = *min_element(cnt.begin(), cnt.end());
        if (mn >= 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    return;
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