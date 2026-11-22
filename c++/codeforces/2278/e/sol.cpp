#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<int> a[2];
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        a[i % 2].push_back(ai);
    }

    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    for (int i = 0; i < n / 2 and a[0][i] + a[1][i] < 0; ++i) {
        swap(a[0][i], a[1][i]);
        a[0][i] *= -1;
        a[1][i] *= -1;
    }

    long long ans = 0;
    ans += accumulate(a[0].begin(), a[0].end(), 0LL);
    ans += accumulate(a[1].begin(), a[1].end(), 0LL);
    cout << ans << '\n';
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