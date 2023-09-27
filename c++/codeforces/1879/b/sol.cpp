#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    ll sum1 = *min_element(a.begin(), a.end()) * n + accumulate(b.begin(), b.end(), 0ll);
    ll sum2 = accumulate(a.begin(), a.end(), 0ll) + *min_element(b.begin(), b.end()) * n;
    cout << min(sum1, sum2) << '\n';
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