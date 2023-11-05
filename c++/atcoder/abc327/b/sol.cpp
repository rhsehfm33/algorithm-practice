#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll B;
    cin >> B;
    for (ll i = 1; i <= 15; ++i) {
        ll result = 1;
        for (ll j = 0; j < i; ++j) {
            result *= i;
        }
        if (result == B) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}