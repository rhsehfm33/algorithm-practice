#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;

    ll sqrt_n = sqrt(n);
    if (sqrt_n * sqrt_n == n) {
        cout << sqrt_n - 1 << '\n';
    }
    else {
        cout << sqrt_n << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}