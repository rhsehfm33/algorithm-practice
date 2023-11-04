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

    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if (sum == 1) {
        cout << 1 << '\n';
        return;
    }
    
    ll ans = sum / 2 + sum % 2; 
    sort(a.begin(), a.end());
    for (ll i = n - 1, cur = 0; i >= 0; --i) {
        ans += 1;
        if (cur + a[i] < sum / 2) {
            cur += a[i];
        } else {
            break;
        }
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