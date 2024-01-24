#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    ll ans = 0, i = 0, j = 0;
    while (i < n) {
        while (j < n and a[i] == a[j]) {
            ++j;
        }
        ans += ((j - i) * (j - i - 1) / 2) * i;
        ans += ((j - i) * (j - i - 1) * (j - i - 2) / 6);
        i = j;
    }
    cout << ans << '\n';
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